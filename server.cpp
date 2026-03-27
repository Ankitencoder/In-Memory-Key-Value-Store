#include "server.h"
#include "parser.h"
#include "persistence.h"
#include "logger.h"

#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

Server::Server(int port) : port(port) {}

void Server::start() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 5);

    Logger::log("Server started on port " + std::to_string(port) + "\n");

    while (true) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        char buffer[1024] = {0};
        read(new_socket, buffer, 1024);

        std::string input(buffer);
        auto tokens = Parser::parse(input);

        std::string response = "ERROR\n";

        if (tokens[0] == "SET" && tokens.size() == 3) {
            store.set(tokens[1], tokens[2]);
            Persistence::append(input);
            response = "OK\n";
        }
        else if (tokens[0] == "GET") {
            response = store.get(tokens[1]) + "\n";
        }
        else if (tokens[0] == "DEL") {
            response = store.del(tokens[1]) ? "1\n" : "0\n";
        }

        send(new_socket, response.c_str(), response.size(), 0);
        close(new_socket);
    }
}
