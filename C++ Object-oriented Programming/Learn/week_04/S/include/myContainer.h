// myContainer.h
#ifndef MY_CONTAINER_H
#define MY_CONTAINER_H

struct myContainer {
    int data[MAX_SIZE];  // Tablica danych
    int N;               // Rozmiar tablicy
    myContainer* spouse; // Wskaźnik na małżonka
    myContainer* parents[2]; // Wskaźniki na rodziców
};

// Maksymalny rozmiar tablicy
#define MAX_SIZE 30

// Funkcje deklarowane w pliku nagłówkowym
void printContainer(const myContainer& container);
void fillContainerWithFibonacci(myContainer& container, int index = 0);
void marry(myContainer& container1, myContainer& container2);
void setParents(myContainer& child, myContainer& parent1, myContainer& parent2);

#endif // MY_CONTAINER_H