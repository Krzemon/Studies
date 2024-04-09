#ifndef GRADE_H
#define GRADE_H

#include "Student.h"
#include "Faculty.h"

class Grade: public virtual Student, public virtual Faculty {
public:
    Grade(const std::string& name, int id, const std::string& spec, int value): Person(name), Student(name, id), Faculty(name, spec), _value(value) {}
    ~Grade() { std::cout << "~" << _value << " (grade)" << std::endl; }

    int GetValue() const { return _value; }

    virtual std::ostream& Print(std::ostream& os) const override {
        os << "As a Student: ";
        Student::Print(os);
        os << std::endl << "As a Faculty: ";
        Faculty::Print(os);
        os << std::endl << "Grade value (grade): " << _value;
        return os;
    }

private:
    int _value;
};

#endif // GRADE_H
