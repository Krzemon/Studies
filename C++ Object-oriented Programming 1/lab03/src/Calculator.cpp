#include "Calculator.h"
#include <iostream>

// konstruktor bezargumentowy
Calculator::Calculator() {}

// konstruktor jednoargumentowy
Calculator::Calculator(int a): value(a) {}

// przeciazony operator postinkrementacji
int Calculator::operator ++(int){
    return value++;
}

// przeciazony operator predekrementacji
int& Calculator::operator --() {
    return --value;
}

// przeciazony operator nawiasowy () bezargumentowy
int Calculator::operator ()(){
    return value;
}

// przeciazony operator nawiasowy () jednoargumentowy
int Calculator::operator ()(std::function<int(int)> fun){
    return fun(value);
}

// przeciazony operator nawiasowy () dwuargumentowy
int Calculator::operator ()(std::function<int(int,int)> fun, int a){
    return fun(value, a);
}

// przeciazony operator mnozenia z prawej
int Calculator::operator *(int a){
    value *= a;
    return value;
}

int operator *(int a, Calculator& obj){
    obj.value *= a;
    return obj.value;
}