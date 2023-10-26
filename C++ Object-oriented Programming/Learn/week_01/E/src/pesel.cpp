#include <iostream>
#include <string>
#include "pesel.h"

bool PeselValidator(const std::string &pesel, int PESEL[11]) {
    if(peselel.length() != 11)
        return false;
    
    for (int i=0; i < 11; ++i) {
        if (pesel[i] < '0' || pesel[i] > '9')
            return false;
        PESEL[i] = pesel[i] - '0';
    }

    if(getCtrlNumber(PESEL) != PESEL[10])
        return false;

    return true;
}

int getCtrlNumber(const int PESEL[11]) {
    int weights[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    for(int i = 0; i < 10; i++)
        sum += PESEL[i] * weights[i];
    return (10 - sum % 10) % 10;
}

int getDay(const int PESEL[11]) {
    int day = PESEL[4] * 10 + PESEL[5];
    if(day > 31)
        day -= 20;
    return day;
}

int getMonth(const int PESEL[11]) {
    int month = PESEL[2] * 10 + PESEL[3];
    if(month > 80)
        month -= 80;
    else if(month > 60)
        month -= 60;
    else if(month > 40)
        month -= 40;
    else if(month > 20)
        month -= 20;
    return month;
}

int getYear(const int PESEL[11]) {
    int year = PESEL[0] * 10 + PESEL[1];
    if(year > 20)
        year += 1900;
    else
        year += 2000;
    return year;
}

void printPesel(const int PESEL[11]) {
    for (int i = 0; i < 11; i++)
        std::cout << PESEL[i];
}
