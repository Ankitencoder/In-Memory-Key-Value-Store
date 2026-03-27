#include "store.h"
#include <chrono>
#include <iostream>

int main() {
    KeyValueStore store;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100000; i++) {
        store.set("key" + std::to_string(i), "value");
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}
