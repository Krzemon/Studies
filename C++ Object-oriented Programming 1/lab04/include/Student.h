#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int id;
public:
    Student(const std::string& name, int id);
    ~Student();
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif // STUDENT_H
