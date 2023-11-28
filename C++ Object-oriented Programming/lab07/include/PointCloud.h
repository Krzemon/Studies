#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <vector>

class APointCloud;
class VPointCloud;

// definicja klasy opisujacej punkt
class Point3D{
public:
    Point3D();
    Point3D(std::array<double, 3> point);
    void displayCoordinates() const;

private:
    friend class APointCloud;
    friend class VPointCloud;
    std::array<double, 3> coordinates_;
};

// definicja klasy opisujacej chmure punktow utwarzona przy pomocy std::array
class APointCloud{
public:
    void addPoint(Point3D point);
    Point3D geoCentre() const;
    void displayPoints() const;
    void displayPoints() const;

private:
    const size_t array_size = 100;
    std::array<Point3D,array_size> arrPoints_;
};

// definicja klasy opisujacej chmure punktow utwarzona przy pomocy std::vector
class VPointCloud{
public:
    void addPoint(const Point3D& point);
    void add(const APointCloud& aPointCloud);
    int count() const;
    Point3D geoCentre() const;

private:
    std::vector<Point3D> vecPoints_;
};

#endif