#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"

class Tiger : public Animal {
public:
    void makeSound() const override;
    void eat() const override;
    void sleep() const override;
    void interact(Animal* other) const override;
    void useSkill() const override;
};

#endif // TIGER_H