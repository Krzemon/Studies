#pragma once
#include <iostream>

class LData {
public:
    virtual void print(std::ostream& os) const = 0;
    virtual bool isSame(const LData& other) const = 0;
    virtual ~LData() {}
};

class IntData : public LData {
private:
    int m_value;
public:
    IntData(int value) : m_value(value) {}
    void print(std::ostream& os) const override { os << m_value; }
    bool isSame(const LData& other) const override {
        try {
            auto& otherInt = dynamic_cast<const IntData&>(other);
            return m_value == otherInt.m_value;
        } catch (std::bad_cast&) {
            return false;
        }
    }
};

class FloatData : public LData {
private:
    float m_value;
public:
    FloatData(float value) : m_value(value) {}
    void print(std::ostream& os) const override { os << m_value; }
    bool isSame(const LData& other) const override {
        try {
            auto& otherFloat = dynamic_cast<const FloatData&>(other);
            return m_value == otherFloat.m_value;
        } catch (std::bad_cast&) {
            return false;
        }
    }
};

class StringData : public LData {
private:
    std::string m_value;
public:
    StringData(const std::string& value) : m_value(value) {}
    void print(std::ostream& os) const override { os << m_value; }
    bool isSame(const LData& other) const override {
        try {
            auto& otherString = dynamic_cast<const StringData&>(other);
            return m_value == otherString.m_value;
        } catch (std::bad_cast&) {
            return false;
        }
    }
};
