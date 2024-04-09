#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student: public virtual Person {
public:
    Student(const std::string& name, int id): Person(name), _id(id) {}
    ~Student() { std::cout << "~" << _id << " (student)" << std::endl; }

    int GetId() const { return _id; }

    virtual std::ostream& Print(std::ostream& os) const override {
        Person::Print(os);
        os << ", id (student): " << _id;
        return os;
    }

private:
    int _id;
};

#endif // STUDENT_H
