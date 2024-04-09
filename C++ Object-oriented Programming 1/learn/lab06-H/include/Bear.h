#ifndef BEAR_H
#define BEAR_H

#include "Animal.h"

class Bear : public Animal {
public:
    void makeSound() const override;
    void eat() const override;
    void sleep() const override;
    void interact(Animal* other) const override;
    void useSkill() const override;
};

#endif // BEAR_H