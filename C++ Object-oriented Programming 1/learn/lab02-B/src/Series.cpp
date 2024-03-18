#include "Series.hpp"
#include <iostream>

Series::Series() {
    std::cout << "Konstruktor klasy Series" << std::endl;
}

Series::~Series() {
    std::cout << "Destruktor klasy Series" << std::endl;
}

Series::Series(const Series& other) {
    std::cout << "Kopiujący konstruktor klasy Series" << std::endl;
    values = other.values;
}

Series& Series::operator=(const Series& other) {
    std::cout << "Kopiujący operator przypisania klasy Series" << std::endl;
    if (this != &other) {
        values = other.values;
    }
    return *this;
}

void Series::append(double value) {
    values.push_back(value);
}

double& Series::operator[](std::size_t index) {
    return values[index];
}

const double& Series::operator[](std::size_t index) const {
    return values[index];
}

std::ostream& operator<<(std::ostream& os, const Series& series) {
    for (const auto& value : series.get_values()) {
        os << value << " ";
    }
    return os;
}

const std::vector<double>& Series::get_values() const {
    return values;
}

Series& Series::operator+=(const Series& other) {
    for (const auto& value : other.values) {
        values.push_back(value);
    }
    return *this;
}
