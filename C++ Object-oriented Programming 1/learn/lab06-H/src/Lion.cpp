#include "Lion.h"

void Lion::makeSound() const {
    std::cout << "Lion roars" << std::endl;
}

void Lion::eat() const {
    std::cout << "Lion eats meet" << std::endl;
}

void Lion::sleep() const {
    // Implementacja snu dla lwa
}

void Lion::interact(Animal* other) const {
    std::cout << "Lion roars at ";
    other->makeSound();
}

void Lion::useSkill() const {
    std::cout << "Lion uses Hyper Voice skill" << std::endl;
}
