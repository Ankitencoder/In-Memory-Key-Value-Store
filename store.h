#ifndef STORE_H
#define STORE_H

#include <unordered_map>
#include <string>
#include <mutex>

class KeyValueStore {
private:
    std::unordered_map<std::string, std::string> store;
    std::mutex mtx;

public:
    void set(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    bool exists(const std::string& key);
};

#endif
