#ifndef LION_H
#define LION_H

#include "Animal.h"

class Lion : public Animal {
public:
    void makeSound() const override;
    void eat() const override;
    void sleep() const override;
    void interact(Animal* other) const override;
    void useSkill() const override;
};

#endif // LION_H