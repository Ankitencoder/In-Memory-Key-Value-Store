#ifndef SERVER_H
#define SERVER_H

#include "store.h"

class Server {
private:
    int port;
    KeyValueStore store;

public:
    Server(int port);
    void start();
};

#endif
