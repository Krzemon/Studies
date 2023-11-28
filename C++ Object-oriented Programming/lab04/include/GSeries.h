#ifndef GSERIES_H
#define GSERIES_H

#include <stdio.h>
#include <iostream> 

typedef float typCiagu;
typedef long int rozmiarCiagu;

const size_t MaxCiagow = 10;
static size_t IleCiagow = 0;

//struktura definiujaca ciag
struct ciagg{
    typCiagu* wyrazy;
    typCiagu iloraz;
    rozmiarCiagu rozmiar;
};

typedef ciagg* ciag; 

//zwraca wskaznik do dynamicznie alokowanej tablicy
ciag InicjalizujCiagGeometryczny(rozmiarCiagu, typCiagu, typCiagu);

//wypisuje tablice zawiarajaca ciag 
void Wypisz(ciag, rozmiarCiagu);

//czysci pamiec zwiazana z alokacja pamieci
void UsunCiagi(void);

#endif