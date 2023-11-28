#include "Angle.h"

// deklaracje zmiennych extern
const char* RADIAN = "RADIAN";
const char* DEGREE = "DEGREE";

// Przeciążone konstruktory
Angle::Angle() : angle_(0.0), unit_(RADIAN) {}

Angle::Angle(double x) : angle_(x), unit_(RADIAN) {}

// funkcja typu klasy wywołująca konstruktor dla argumentu jednostki radian
// konwertująca do jednostki radian i wartość kąta do zakresu [0,2pi)
Angle Angle::fromRadians(double value) {
    while (value < 0.0) {
        value += 2 * M_PI;
    }
    while (value > 2 * M_PI) {
        value -= 2 * M_PI;
    }
    std::cout << "... creating angle from radians." << std::endl;
    return Angle(value);
}

// funkcja typu klasy wywołująca konstruktor dla argumentu jednostki stopień,
// konwertująca do jednostki radian i wartość kąta do zakresu [0,2pi)
Angle Angle::fromDegrees(double val) {
    double value = val * M_PI / 180.0;
    while (value < 0.0) {
        value += 2 * M_PI;
    }
    while (value > 2 * M_PI) {
        value -= 2 * M_PI;
    }
    std::cout << "... creating angle from degrees." << std::endl;
    return Angle(value);
}

// funkcja zwracająca kąt w radianach
double Angle::toRad() const {
    if (unit_ == DEGREE) {
        return angle_ * M_PI / 180.0;
    }
    return angle_;
}

// funkcja zwracająca kąt w stopniach
double Angle::toDeg() const {
    if (unit_ == RADIAN) {
        return angle_ * 180.0 / M_PI;
    }
    return angle_;
}

// Angles[rad]: phi1=5.16681 phi2=0.0872665
void Angle::print() const {
    std::cout << "Angle [" << unit_ << "]: " << angle_ << std::endl;
}

// funkcja zwracająca obiekt, który ma kąt równy sumie kątów obiektów przekazanych
Angle& Angle::add(const Angle& other) {
    angle_ += other.toRad();
    return *this;
}

// funkcja obliczająca odległość pomiędzy kątami w kącie w radianach
Angle Angle::distance(const Angle& one, const Angle& two) {
    double x = one.toRad() - two.toRad();
    return fromRadians(std::abs(x));
}

// destruktor
Angle::~Angle() {}
