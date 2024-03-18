#include "Dictionary.h"

void Dictionary::add(const std::string& key, int value) {
    data[key] = value;
}

int& Dictionary::operator[](const std::string& key) {
    return data[key];
}

int Dictionary::operator[](const std::string& key) const {
    return data.at(key);
}

void Dictionary::remove(const std::string& key) {
    data.erase(key);
}

Dictionary Dictionary::move() noexcept {
    return std::move(*this);
}
