#include "combined.h"

double calculate_common_area(double xA, double RA, double RB) {
    double distance = std::abs(xA - 0) - (RA + RB);
    if (distance >= 0)
        return 0;
    else if (distance < 0 && std::abs(distance) < RA && RA < RB) {
        double phi = 2 * std::acos(distance / (2 * RA));
        double common_area = 0.5 * (phi - std::sin(phi)) * RA * RA;
        return common_area;
    } else if (distance < 0 && std::abs(distance) < RB && RA > RB) {
        double phi = 2 * std::acos(distance / (2 * RB));
        double common_area = 0.5 * (phi - std::sin(phi)) * RB * RB;
        return common_area;
    } else
        return 0;
}

std::vector<Point> generate_points_in_circle(double x_center, double y_center, double radius, int N) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_x(x_center - radius, x_center + radius);
    std::uniform_real_distribution<> dis_y(y_center - radius, y_center + radius);

    std::vector<Point> points;
    for (int i = 0; i < N; ++i) {
        double x = dis_x(gen);
        double y = dis_y(gen);
        if ((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center) <= radius * radius) {
            points.push_back({x, y});
        }
    }
    return points;
}