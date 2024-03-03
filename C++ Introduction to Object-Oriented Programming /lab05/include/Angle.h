#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>
#include <cmath>
#include <cstring>

extern const char* RADIAN;
extern const char* DEGREE;

class Angle{
public:
    Angle();
    Angle(double value, const char* unit);
    ~Angle();

    double toRad() const;
    double toDeg() const;
    void add(const Angle& other);
private:
    double angle;
    const char* si;
};

#endif