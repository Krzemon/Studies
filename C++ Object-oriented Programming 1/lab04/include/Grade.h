#ifndef GRADE_H
#define GRADE_H

#include "Student.h"
#include "Faculty.h"

class Grade : public Student, public Faculty {
private:
    double value;
public:
    Grade(const std::string& name, int id, const std::string& specialization, double value);
    ~Grade();
    friend std::ostream& operator<<(std::ostream& os, const Grade& grade);
};

#endif // GRADE_H
