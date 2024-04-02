#include "Faculty.h"

Faculty::Faculty(const std::string& name, const std::string& specialization)
    : Person(name), specialization(specialization) {}

Faculty::~Faculty() {}

std::ostream& operator<<(std::ostream& os, const Faculty& faculty) {
    os << static_cast<const Person&>(faculty) << ", Specialization: " << faculty.specialization;
    return os;
}
