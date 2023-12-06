#include "PointCloud.h"

// Implementacja klasy Point3D
Point3D::Point3D(std::array<double, 3> coordinates) : coordinates_(coordinates) {}

void Point3D::displayCoordinates() const {
    std::cout << "(" << coordinates_[0] << ", " << coordinates_[1] << ", " << coordinates_[2] << ")";
}

APointCloud::APointCloud() : count_(0) {}

APointCloud::~APointCloud() {}

void APointCloud::addPoint(const Point3D& point) {
    if (count_ < MAX_POINTS) {
        points_[count_] = point;
        count_++;
    } else {
        std::cerr << "Przekroczono maksymalną liczbę punktów!" << std::endl;
    }
}

Point3D APointCloud::geoCentre() const {
    if (count_ == 0) {
        return Point3D({0.0, 0.0, 0.0});
    }

    double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    for (size_t i = 0; i < count_; ++i) {
        sumX += points_[i].getCoordinates()[0];
        sumY += points_[i].getCoordinates()[1];
        sumZ += points_[i].getCoordinates()[2];
    }

    double centerX = sumX / count_;
    double centerY = sumY / count_;
    double centerZ = sumZ / count_;

    return Point3D({centerX, centerY, centerZ});
}

void APointCloud::displayPoints() const {
    std::cout << "Chmura punktów [APC]:" << std::endl;
    for (size_t i = 0; i < count_; ++i) {
        points_[i].displayCoordinates();
        std::cout << std::endl;
    }
}

// Implementacja klasy VPointCloud
void VPointCloud::addPoint(const Point3D& point) {
    points_.push_back(point);
}

void VPointCloud::add(const APointCloud& aPointCloud) {
    for (size_t i = 0; i < aPointCloud.count_; ++i) {
        points_.push_back(aPointCloud.points_[i]);
    }
}

size_t VPointCloud::count() const {
    return points_.size();
}

Point3D VPointCloud::geoCentre() const {
    if (points_.empty()) {
        return Point3D({0.0, 0.0, 0.0});
    }

    double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    for (const auto& point : points_) {
        sumX += point.getCoordinates()[0];
        sumY += point.getCoordinates()[1];
        sumZ += point.getCoordinates()[2];
    }

    double centerX = sumX / points_.size();
    double centerY = sumY / points_.size();
    double centerZ = sumZ / points_.size();

    return Point3D({centerX, centerY, centerZ});
}

void VPointCloud::displayPoints() const {
    std::cout << "Chmura punktów [VPC]:";
    for (const auto& point : points_) {
        std::cout << std::endl;
        point.displayCoordinates();
    }
    std::cout << std::endl;
}
