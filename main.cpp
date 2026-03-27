#include <iostream>
#include "store.h"
#include "persistence.h"

int main() {
    KeyValueStore store;
    std::string cmd, key, value;

    while (true) {
        std::cin >> cmd;

        if (cmd == "SET") {
            std::cin >> key >> value;
            store.set(key, value);
            Persistence::append("SET " + key + " " + value);
            std::cout << "OK\n";
        } 
        else if (cmd == "GET") {
            std::cin >> key;
            std::cout << store.get(key) << std::endl;
        } 
        else if (cmd == "EXIT") {
            break;
        }
    }
}
