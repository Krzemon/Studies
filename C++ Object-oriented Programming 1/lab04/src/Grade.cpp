#include "Grade.h"

Grade::Grade(const std::string& name, int id, const std::string& specialization, double value)
    : Student(name, id), Faculty(name, specialization), value(value) {}

Grade::~Grade() {}

std::ostream& operator<<(std::ostream& os, const Grade& grade) {
    os << static_cast<const Student&>(grade) << ", Specialization: " << grade.specialization
       << ", Grade: " << grade.value;
    return os;
}
