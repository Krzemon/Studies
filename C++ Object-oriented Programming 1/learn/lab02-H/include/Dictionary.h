#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <unordered_map>
#include <string>

class Dictionary {
private:
    std::unordered_map<std::string, int> data;

public:
    void add(const std::string& key, int value);
    int& operator[](const std::string& key);
    int operator[](const std::string& key) const;
    void remove(const std::string& key);
    Dictionary move() noexcept;
};

#endif // DICTIONARY_H
