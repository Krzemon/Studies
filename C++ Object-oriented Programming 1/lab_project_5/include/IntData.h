#ifndef INTDATA_H
#define INTDATA_H

#include "Data.h"

class IntData : public Data {
private:
    int value;
public:
    IntData(int val);
    ~IntData() override;

    std::unique_ptr<Data> clone() const override;
    void print(std::ostream& os) const override;
};

#endif // INTDATA_H

