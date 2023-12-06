#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <vector>

class VPointCloud;


class Point3D {
public:
    Point3D() = default;
    Point3D(std::array<double, 3> coordinates);
    void displayCoordinates() const;
    const std::array<double, 3>& getCoordinates() const {return coordinates_;}

private:
    std::array<double, 3> coordinates_;
};

class APointCloud {
public:
    APointCloud();
    ~APointCloud();
    void addPoint(const Point3D& point);
    Point3D geoCentre() const;
    void displayPoints() const;

private:
    std::array<Point3D, 100> points_;
    size_t count_;
    static const size_t MAX_POINTS = 100;
    friend class VPointCloud;
};

class VPointCloud {
public:
    void addPoint(const Point3D& point);
    void add(const APointCloud& aPointCloud);
    size_t count() const;
    Point3D geoCentre() const;
    void displayPoints() const;

private:
    std::vector<Point3D> points_;
};

#endif
