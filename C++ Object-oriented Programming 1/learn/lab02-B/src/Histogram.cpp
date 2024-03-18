#include "Histogram.hpp"
#include <iostream>

Histogram::Histogram() {
    std::cout << "Konstruktor klasy Histogram" << std::endl;
}

Histogram::~Histogram() {
    std::cout << "Destruktor klasy Histogram" << std::endl;
}

Histogram::Histogram(const Histogram& other) {
    std::cout << "Kopiujący konstruktor klasy Histogram" << std::endl;
    data = other.data;
}

Histogram& Histogram::operator=(const Histogram& other) {
    std::cout << "Kopiujący operator przypisania klasy Histogram" << std::endl;
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

void Histogram::add_series(const std::string& name) {
    data[name] = Series();
}

Series& Histogram::operator[](const std::string& name) {
    return data[name];
}

const Series& Histogram::operator[](const std::string& name) const {
    return data.at(name);
}

std::vector<std::string> Histogram::get_series_names() const {
    std::vector<std::string> names;
    for (const auto& pair : data) {
        names.push_back(pair.first);
    }
    return names;
}
