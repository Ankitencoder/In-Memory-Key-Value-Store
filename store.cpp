#include "store.h"

void KeyValueStore::set(const std::string& key, const std::string& value) {
    std::unique_lock lock(mutex);
    store[key] = value;
}

std::string KeyValueStore::get(const std::string& key) const {
    std::shared_lock lock(mutex);
    auto it = store.find(key);
    return it != store.end() ? it->second : "NULL";
}

bool KeyValueStore::del(const std::string& key) {
    std::unique_lock lock(mutex);
    return store.erase(key);
}
