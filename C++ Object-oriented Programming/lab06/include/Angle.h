#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>
#include <cmath>
#include <cstring>

// Zmienne, których definicja znajduje się w osobnym pliku
extern const char* RADIAN;
extern const char* DEGREE;

// Klasa operująca na obiekcie będącym kątem, konstruktor konwertuje kąt 
// domyślnie na radiany z zakresu [0,2pi)
class Angle {
public:
    Angle();
    Angle(double x);
    ~Angle();

    static Angle fromRadians(double value);
    static Angle fromDegrees(double value);

    double toRad() const;
    double toDeg() const;

    static Angle distance(const Angle& one, const Angle& two);

    void print() const;
    Angle& add(const Angle& other);

private:
    double angle_;
    const char* unit_;
};

#endif
