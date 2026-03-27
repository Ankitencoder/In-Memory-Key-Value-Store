#ifndef SERVER_H
#define SERVER_H

#include "store.h"

class Server {
private:
    KeyValueStore store;

public:
    void start();
};

#endif
