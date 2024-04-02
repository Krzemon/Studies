#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <functional>

// dokumentacja w .cpp
class Calculator{
public:
    Calculator();
    Calculator(int a);
    int operator ++(int);
    int& operator --();
    int operator ()();
    int operator ()(std::function<int(int)> fun);
    int operator ()(std::function<int(int,int)> fun, int a);
    int operator *(int a);

    int value;
};

// przeciazony operator mnozenia z lewej
int operator *(int a, Calculator& obj);

#endif // CALCULATOR_H