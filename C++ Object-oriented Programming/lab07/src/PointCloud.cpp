#include "PointCloud.h"

// POINT
// konstruktor domyslny tworzacy punkt (0,0,0)
Point3D::Point3D() : coordinate_({0.0, 0.0, 0.0}) {}
 
// konstruktor tworzacy punkt przekazany do argumentu postaci {double, double, double}
Point3D::Point3D(std::array<double, 3> point) : coordinate_(point) {}

// procedura wypisujaca koordynaty obiektu (punktu) na ktorym jest wywolywana 
void Point3D::displayCoordinates() const {
    std::cout << "(" << coordinate_[0] << ", " << coordinate_[1] << ", " << coordinate_[2] << ")";
}


// VECTOR
// procedura wypisujaca koordynaty obiektu (zbioru punktow) na ktorym jest wywolywana 
void VPointCloud::displayPoints() const {
    std::cout << "Chmura punktów [VPC]:";
    for (const auto& point: vecPoints_){
        std::cout << std::endl;
        point.displayCoordinates();
    }
}

void VPointCloud::addPoint(const Point3D& point) {
    vecPoints_.push_back(point);
}

int VPointCloud::count() const{
    return vecPoints_.size();
}

Point3D VPointCloud::geoCentre(){
    double x, y, z;
    for(const auto& point: vecPoint_){
        x += point.coordinates_[0];
        y += point.coordinates_[1];
        z += point.coordinates_[2];
    }

    int my_size = this->count();
    x /= my_size;
    y /= my_size;
    z /= my_size;
    Point3D center_point ({x, y, z});
    return center_point;
}


void VPointCloud::add(const APointCloud& aPointCloud) {
    for (const auto& point : aPointCloud.points_) {
        points_.push_back(point);
    }
}