#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public Person {
private:
    std::string specialization;
public:
    Faculty(const std::string& name, const std::string& specialization);
    ~Faculty();
    friend std::ostream& operator<<(std::ostream& os, const Faculty& faculty);
};

#endif // FACULTY_H
