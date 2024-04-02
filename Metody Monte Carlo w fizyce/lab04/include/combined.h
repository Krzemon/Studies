#ifndef COMBINED_H
#define COMBINED_H

#include <iostream>
#include <cmath>
#include <vector>
#include <random>

// Struktura punktu 2D
struct Point {
    double x;
    double y;
};

// Obliczanie wspólnej powierzchni przekrywających się kół
double calculate_common_area(double xA, double RA, double RB);

// Funkcja generująca punkty w kole
std::vector<Point> generate_points_in_circle(double x_center, double y_center, double radius, int N);

#endif // COMBINED_H