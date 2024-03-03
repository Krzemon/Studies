#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
private:
    std::string name;
    double x, y;

public:
    Point();
    Point(std::string n);
    Point(std::string n, double xVal, double yVal);

    void SetName(std::string n);
    void SetX(double xVal);
    void SetY(double yVal);

    void Presentation();
};

#endif