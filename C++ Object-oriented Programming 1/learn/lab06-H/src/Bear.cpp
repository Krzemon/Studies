#include "Bear.h"

void Bear::makeSound() const {
    std::cout << "Bear grunts" << std::endl;
}

void Bear::eat() const {
    std::cout << "Bear eats fish" << std::endl;
}

void Bear::sleep() const {
    // Implementacja snu dla niedźwiedzia
}

void Bear::interact(Animal* other) const {
    std::cout << "Bear grunts at ";
    other->makeSound();
}

void Bear::useSkill() const {
    std::cout << "Bear uses Belly Drum skill" << std::endl;
}