#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
public:
    Person(const std::string& name);
    virtual ~Person();
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

#endif // PERSON_H
