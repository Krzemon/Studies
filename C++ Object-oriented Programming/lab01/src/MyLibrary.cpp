#include "MyLibrary.h"
#include <iostream>

void PrintName(const char* name) {
    char message[100];
    sprintf(message, "Name: %s", name);
    PrintInfo(message);
}

void PrintInfo(const char* path) {
    char fullMessage[100];
    sprintf(fullMessage, "[INFO]:: %s", path);
    std::cout << fullMessage << std::endl;
}
