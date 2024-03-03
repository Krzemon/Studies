#include "cardVerificationUtilities.h"
#include <cstring>

char getControlNum(const char* cardNum) {
    int sum = 0;
    int i = 0;
    while (cardNum[i] != '\0') {
        if (i % 2 == 0) {
            sum += (cardNum[i] - '0') * 2;
        } else {
            sum += (cardNum[i] - '0');
        }
        i++;
    }
    return (sum % 10 == 0) ? '0' : (sum % 10) + '0';
}

bool checkNum(const char* cardNum) {
    int cardLength = strlen(cardNum);
    if (cardLength != 13) {
        return false; // Niepoprawna długość numeru
    }

    if (getControlNum(cardNum) == '0') {
        return true; // Poprawny numer
    } else {
        return false; // Niepoprawny numer
    }
}
