#include "store.h"

void KeyValueStore::set(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mtx);
    store[key] = value;
}

std::string KeyValueStore::get(const std::string& key) {
    std::lock_guard<std::mutex> lock(mtx);
    if (store.find(key) != store.end())
        return store[key];
    return "NULL";
}

bool KeyValueStore::exists(const std::string& key) {
    std::lock_guard<std::mutex> lock(mtx);
    return store.find(key) != store.end();
}
