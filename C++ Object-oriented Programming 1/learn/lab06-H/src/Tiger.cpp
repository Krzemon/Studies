#include "Tiger.h"

void Tiger::makeSound() const {
    std::cout << "Tiger growls" << std::endl;
}

void Tiger::eat() const {
    std::cout << "Tiger eats meet" << std::endl;
}

void Tiger::sleep() const {
    // Implementacja snu dla tygrysa
}

void Tiger::interact(Animal* other) const {
    std::cout << "Tiger stares at ";
    other->makeSound();
}

void Tiger::useSkill() const {
    std::cout << "Tiger uses Flare Blitz skill" << std::endl;
}