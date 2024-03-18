#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP

#include <map>
#include <string>
#include "Series.hpp"

class Histogram {
private:
    std::map<std::string, Series> data;

public:
    Histogram(); // Dodanie konstruktora
    ~Histogram(); // Dodanie destruktora
    Histogram(const Histogram& other); // Dodanie kopiującego konstruktora
    Histogram& operator=(const Histogram& other); // Dodanie kopiującego operatora przypisania
    void add_series(const std::string& name);
    Series& operator[](const std::string& name);
    const Series& operator[](const std::string& name) const;
    std::vector<std::string> get_series_names() const;
};

#endif /* HISTOGRAM_HPP */
