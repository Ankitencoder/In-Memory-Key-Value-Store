# Redis-like In-Memory Key-Value Store (C++)

A high-performance in-memory key-value database inspired by Redis.

## 🚀 Features
- O(1) average read/write using hash map
- Thread-safe operations (mutex locking)
- Append-only file persistence (AOF)
- Modular architecture (parser, server, storage)
- Basic CLI command system

## 🧠 Architecture
Client Input → Parser → Command Handler → Store → Persistence

## 📌 Commands
SET key value  
GET key  
EXIT  

## 🧪 Testing
g++ tests/test_store.cpp src/store.cpp -o test  
./test  

## ⚡ Future Improvements
- TCP server (networked Redis clone)
- LRU eviction policy
- Snapshotting (RDB)
- Replication


kv-store-cpp/
├── src/
│   ├── main.cpp
│   ├── server.cpp
│   ├── store.cpp
│   ├── persistence.cpp
│   ├── parser.cpp
│   └── benchmark.cpp
├── include/
│   ├── server.h
│   ├── store.h
│   ├── persistence.h
│   ├── parser.h
├── data/
│   └── appendonly.aof
├── Makefile
└── README.md



