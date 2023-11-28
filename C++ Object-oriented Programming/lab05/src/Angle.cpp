#include "Angle.h"

const char* RADIAN = "RADIAN";
const char* DEGREE = "DEGREE";

Angle::Angle() : angle(0.0), si(RADIAN) {}

Angle::Angle(double value, const char* unit) : si(RADIAN){
    if (strcmp(unit, DEGREE) == 0) {
        value = value * M_PI / 180.0;
        std::cout << "... creating angle from degrees."<< std::endl;
    }
    else{
        std::cout << "... creating angle from radians."<< std::endl;
    }

    while (value < 0.0) {
        value += 2 * M_PI;
    }
    while (value > 2 * M_PI) {
        value -= 2 * M_PI;
    }

    angle = value;
}

double Angle::toRad() const {
    // if (strcmp(si, DEGREE) == 0) {
    //     return angle * M_PI / 180.0;
    // }
    return angle;
}

double Angle::toDeg() const {
    if (strcmp(si, RADIAN) == 0) {
        return angle * 180.0 / M_PI;
    }
    return angle;
}

void Angle::add(const Angle& other) {
    angle += other.toRad();
}

Angle::~Angle() {}
