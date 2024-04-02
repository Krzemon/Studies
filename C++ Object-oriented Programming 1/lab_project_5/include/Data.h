#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <memory>

class Data {
public:
    virtual ~Data() {}
    virtual std::unique_ptr<Data> clone() const = 0;
    virtual void print(std::ostream& os) const = 0;
};

#endif // DATA_H
