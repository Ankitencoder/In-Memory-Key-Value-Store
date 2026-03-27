# Redis-Inspired In-Memory Key-Value Store (C++)

## 🚀 Overview
A high-performance in-memory key-value store inspired by Redis, designed for low-latency operations and durability using append-only persistence.

## ⚙️ Features
- O(1) average read/write using hash map
- Thread-safe with shared_mutex
- Append-Only File (AOF) persistence
- Command parser (SET, GET, DEL)
- Benchmarking tool

## 🧠 Design Decisions
- Read-heavy optimization using shared locks
- Write durability via AOF
- Trade-off: Slight write latency for persistence

## 📊 Benchmark
100k writes: ~X ms (depends on system)

## 🛠 Run
make
./kvstore

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



