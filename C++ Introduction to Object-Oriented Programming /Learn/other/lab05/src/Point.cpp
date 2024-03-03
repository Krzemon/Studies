#include "Point.h"
#include <iostream>

Point::Point() : name(""), x(0.0), y(0.0) {}
Point::Point(std::string n) : name(n), x(0.0), y(0.0) {}
Point::Point(std::string n, double xVal, double yVal) : name(n), x(xVal), y(yVal) {}

void Point::SetName(std::string n) { name = n; }
void Point::SetX(double xVal) { x = xVal; }
void Point::SetY(double yVal) { y = yVal; }

void Point::Presentation() {
    std::cout << "Point " << name << ": (" << x << ", " << y << ")" << std::endl;
}
