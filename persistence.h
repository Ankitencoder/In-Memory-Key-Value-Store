#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>

class Persistence {
public:
    static void append(const std::string& command);
};

#endif
