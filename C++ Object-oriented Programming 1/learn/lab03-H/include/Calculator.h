#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <functional>

class Calculator {
private:
    int value;

public:
    Calculator() : value(0) {}

    Calculator(int initialValue) : value(initialValue) {}

    int operator()() const {
        return value;
    }

    void operator=(int val) {
        value = val;
    }

    int operator++() {
        return ++value;
    }

    int operator--() {
        return --value;
    }

    int operator*(int multiplier) {
        return value * multiplier;
    }

    int operator()(std::function<int(int, int)> func, int a, int b) {
        return func(a, b);
    }

    int operator()(std::function<int(int)> func) {
        return func(value);
    }

    int operator()(std::function<int(int, int)> func, int a) {
        return func(value, a);
    }
};

#endif //CALCULATOR_H
