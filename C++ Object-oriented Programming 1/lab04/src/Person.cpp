#include "Person.h"

Person::Person(const std::string& name) : name(name) {}

Person::~Person() {}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Name: " << person.name;
    return os;
}
