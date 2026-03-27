#include "persistence.h"
#include <fstream>

void Persistence::append(const std::string& command) {
    std::ofstream file("data/appendonly.aof", std::ios::app);
    file << command << "\n";
}
