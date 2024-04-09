#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty: public virtual Person {
public:
    Faculty(const std::string& name, const std::string& spec): Person(name), _spec(spec) {}
    ~Faculty() { std::cout << "~" << _spec << " (faculty)" << std::endl; }

    std::string GetSpec() const { return _spec; }

    virtual std::ostream& Print(std::ostream& os) const override {
        Person::Print(os);
        os << ", spec (faculty): " << _spec;
        return os;
    }

private:
    std::string _spec;
};

#endif // FACULTY_H
