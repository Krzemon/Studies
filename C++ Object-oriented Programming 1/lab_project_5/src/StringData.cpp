#include "StringData.h"

StringData::StringData(const std::string& val) : value(val) {}

StringData::~StringData() {}

std::unique_ptr<Data> StringData::clone() const {
    return std::make_unique<StringData>(*this);
}

void StringData::print(std::ostream& os) const {
    os << '"' << value << '"';
}

