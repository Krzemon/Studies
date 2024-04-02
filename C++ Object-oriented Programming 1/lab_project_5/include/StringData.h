#ifndef STRINGDATA_H
#define STRINGDATA_H

#include "Data.h"
#include <string>

class StringData : public Data {
private:
    std::string value;
public:
    StringData(const std::string& val);
    ~StringData() override;

    std::unique_ptr<Data> clone() const override;
    void print(std::ostream& os) const override;
};

#endif // STRINGDATA_H
