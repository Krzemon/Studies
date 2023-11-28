// myContainer.cpp
#include "myContainer.h"
#include <iostream>

// Funkcja do wypisywania postaci myContainer
void printContainer(const myContainer& container) {
    std::cout << "[";
    for (int i = 0; i < container.N; ++i) {
        std::cout << container.data[i];
        if (i < container.N - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]";
    if (container.spouse) {
        std::cout << " is married to ";
        printContainer(*container.spouse);
    }
    if (container.parents[0] && container.parents[1]) {
        std::cout << " and has parents ";
        printContainer(*container.parents[0]);
        std::cout << " and ";
        printContainer(*container.parents[1]);
    }
    std::cout << std::endl;
}

// Funkcja do wypełniania tablicy danymi z ciągu Fibonacciego
void fillContainerWithFibonacci(myContainer& container, int index) {
    if (index >= container.N) {
        return;
    }

    if (index == 0 || index == 1) {
        container.data[index] = 1;
    } else {
        container.data[index] = container.data[index - 1] + container.data[index - 2];
    }

    fillContainerWithFibonacci(container, index + 1);
}

// Funkcja do ustawiania małżonka dla dwóch kontenerów
void marry(myContainer& container1, myContainer& container2) {
    container1.spouse = &container2;
    container2.spouse = &container1;
}

// Funkcja do ustawiania rodziców dla dziecka
void setParents(myContainer& child, myContainer& parent1, myContainer& parent2) {
    child.parents[0] = &parent1;
    child.parents[1] = &parent2;
}
