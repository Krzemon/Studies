#include "Student.h"

Student::Student(const std::string& name, int id) : Person(name), id(id) {}

Student::~Student() {}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << static_cast<const Person&>(student) << ", ID: " << student.id;
    return os;
}
