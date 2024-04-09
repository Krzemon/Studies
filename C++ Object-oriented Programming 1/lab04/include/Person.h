#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    Person(const std::string& name): _name(name) {}
    virtual ~Person() { std::cout << "~" << _name << " (person)" << std::endl; }

    std::string GetName() const { return _name; }

    virtual std::ostream& Print(std::ostream& os) const {
        os << "name (person): " << _name;
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        return person.Print(os);
    }

protected:
    std::string _name;
};

#endif // PERSON_H
