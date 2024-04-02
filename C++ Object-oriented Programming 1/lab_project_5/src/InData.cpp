#include "IntData.h"

IntData::IntData(int val) : value(val) {}

IntData::~IntData() {}

std::unique_ptr<Data> IntData::clone() const {
    return std::make_unique<IntData>(*this);
}

void IntData::print(std::ostream& os) const {
    os << value;
}
