#include "PointCloud.h"
#include <iomanip>

int Point3D::DISPLAY_PRESITION = 1;
size_t count_ = 0;

//************** Implementacja klasy Point3D **************//

Point3D::Point3D(std::array<double, 3> coordinates) : coordinates_(coordinates) {}
Point3D::Point3D(double xyz) : coordinates_({xyz,xyz,xyz}) {}

void Point3D::displayCoordinates() const {
    std::cout << std::fixed << std::setprecision(DISPLAY_PRESITION);
    std::cout<< "(" << coordinates_[0]<< ", " << coordinates_[1] << ", " << coordinates_[2] << ")" << std::endl;
}


//************** Implementacja klasy VPointCloud **************//

void VPointCloud::addPoint(Point3D* point) {
    wsk_to_points_.push_back(point);
}

void VPointCloud::addPoint(std::array<double, 3> coordinates) {
   wsk_to_points_.push_back(new Point3D(coordinates));
}



size_t VPointCloud::count() const {
    return wsk_to_points_.size();
}

Point3D VPointCloud::geoCentre() const {
    if (wsk_to_points_.empty()) {
        return Point3D({0.0, 0.0, 0.0});
    }

    double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    for (const auto& point_wsk : wsk_to_points_) {
        sumX += point_wsk->coordinates_[0];
        sumY += point_wsk->coordinates_[1];
        sumZ += point_wsk->coordinates_[2];
    }

    double centerX = sumX / wsk_to_points_.size();
    double centerY = sumY / wsk_to_points_.size();
    double centerZ = sumZ / wsk_to_points_.size();

    return Point3D({centerX, centerY, centerZ});
}

void VPointCloud::displayPoints() const {
    std::cout << "Chmura punktów [VPC]:" << std::endl;
    for (const auto& point : wsk_to_points_) {
        point->displayCoordinates();
    }
    // std::cout << std::endl;
}

Point3D* VPointCloud::getCopyPoint(size_t i) {
    return new Point3D(*wsk_to_points_[i]);
}


void VPointCloud::add(const VPointCloud& vPointCloud) {
    for (const auto& point: vPointCloud.wsk_to_points_){
        wsk_to_points_.push_back(point);
    }

    // for (size_t i = 0; i < vPointCloud.count_; ++i) {
    //     wsk_to_points_.push_back(vPointCloud.wsk_to_points_[i]);
    // }
}

