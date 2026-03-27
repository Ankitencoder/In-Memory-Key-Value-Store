#include "server.h"
#include "parser.h"
#include "persistence.h"
#include <iostream>

void Server::start() {
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        auto tokens = Parser::parse(input);

        if (tokens.empty()) continue;

        if (tokens[0] == "SET" && tokens.size() == 3) {
            store.set(tokens[1], tokens[2]);
            Persistence::append(input);
            std::cout << "OK\n";
        }
        else if (tokens[0] == "GET") {
            std::cout << store.get(tokens[1]) << "\n";
        }
        else if (tokens[0] == "DEL") {
            std::cout << store.del(tokens[1]) << "\n";
        }
        else if (tokens[0] == "EXIT") break;
    }
}
