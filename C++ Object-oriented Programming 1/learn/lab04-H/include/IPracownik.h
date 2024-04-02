#ifndef IPRACOWNIK_H
#define IPRACOWNIK_H

#include <iostream>

class IPracownik {
public:
    virtual ~IPracownik() {}
    virtual void przedstawSie() const = 0;
    virtual void ReleaseFromWork() = 0;
};

#endif // IPRACOWNIK_H
