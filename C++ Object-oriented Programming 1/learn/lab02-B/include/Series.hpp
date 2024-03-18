#ifndef SERIES_HPP
#define SERIES_HPP

#include <vector>
#include <ostream>

class Series {
private:
    std::vector<double> values;

public:
    Series(); // Dodanie konstruktora
    ~Series(); // Dodanie destruktora
    Series(const Series& other); // Dodanie kopiującego konstruktora
    Series& operator=(const Series& other); // Dodanie kopiującego operatora przypisania
    void append(double value);
    double& operator[](std::size_t index);
    const double& operator[](std::size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, const Series& series);
    Series& operator+=(const Series& other);
    const std::vector<double>& get_values() const;
};

#endif // SERIES_HPP
