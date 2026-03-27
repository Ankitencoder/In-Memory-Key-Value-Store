
# 🚀 In-Memory Key-Value Store (C++)

## 📌 1. Overview

This project is a **Redis-inspired in-memory key-value store** built in C++.
It is designed to support **fast data access (O(1))**, ensure **thread safety**, and provide **durability using disk persistence**.

The system also includes a **TCP server**, allowing external clients to interact with it in real time.

---

## 🎯 2. Goals of the Project

* Understand **system design fundamentals**
* Learn **concurrency handling**
* Explore **low-latency data structures**
* Implement **persistence mechanisms**
* Build a **real-world backend system**

---

## ⚙️ 3. Key Features

### 🧠 Core Operations

* `SET key value` → Store a value
* `GET key` → Retrieve a value
* `DEL key` → Delete a key

All operations run in **O(1) average time** using a hash map.

---

### 🔒 Thread Safety

* Uses `shared_mutex`
* Multiple readers allowed simultaneously
* Writers get exclusive access
* Prevents **race conditions**

---

### 💾 Persistence (AOF - Append Only File)

* Every write operation is logged to disk
* File: `data/appendonly.aof`
* Ensures data survives restarts

**Trade-off:**

* Slightly slower writes
* Stronger durability

---

### 🌐 TCP Server

* Runs on **port 8080**
* Accepts commands from external clients

Example:

```bash
telnet localhost 8080
```

---

### 📊 Benchmarking

* Measures performance of large workloads
* Example: 200,000 writes timing

---

## 🏗️ 4. System Architecture

Flow of execution:

Client
↓
TCP Server
↓
Command Parser
↓
Key-Value Store
↓
Persistence Layer

---

## 🔄 5. Step-by-Step Execution Flow

### Step 1: Client Sends Command

User connects via terminal:

```bash
telnet localhost 8080
```

---

### Step 2: Server Receives Input

* TCP server reads incoming request
* Converts it into a string

---

### Step 3: Command Parsing

* Input is split into tokens
* Example:

```
SET name Ankit
→ ["SET", "name", "Ankit"]
```

---

### Step 4: Command Execution

#### SET

* Stores key-value pair
* Writes to memory
* Appends to AOF file

#### GET

* Looks up key in hash map
* Returns value or NULL

#### DEL

* Removes key from store
* Returns success status

---

### Step 5: Response Sent Back

* Server sends result to client
* Example:

```
OK
Ankit
1
```

---

## ⚡ 6. Concurrency Design

| Operation | Lock Type   |
| --------- | ----------- |
| GET       | Shared Lock |
| SET/DEL   | Unique Lock |

### Why this matters:

* Improves performance in read-heavy workloads
* Prevents data corruption

---

## 📊 7. Performance Analysis

| Operation | Complexity |
| --------- | ---------- |
| SET       | O(1) avg   |
| GET       | O(1) avg   |
| DEL       | O(1) avg   |

### Trade-offs:

* Persistence → safer but slower writes
* Locking → safe but slight overhead

---

## 🛠️ 8. How to Run

### Build Project

```bash
make
```

### Run Server

```bash
./kvstore
```

---

## 🔌 9. Connect to Server

```bash
telnet localhost 8080
```

---

## 🧪 10. Example Usage

```bash
SET language C++
OK

GET language
C++

DEL language
1
```

---

## 📈 11. Run Benchmark

```bash
make benchmark
./benchmark
```

---

## 🧠 12. Key Learnings

* Handling **race conditions**
* Designing **low-latency systems**
* Understanding **consistency vs performance**
* Working with **TCP sockets**
* Implementing **real-world backend logic**

---

## 🚀 13. Future Improvements

* Multi-threaded client handling (thread pool)
* LRU cache eviction
* Snapshot-based persistence (like Redis RDB)
* Replication (master-slave)
* Distributed clustering

---

## 🔗 14. GitHub Repository
https://github.com/Ankitencoder/In-Memory-Key-Value-Store


