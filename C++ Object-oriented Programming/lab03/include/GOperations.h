#ifndef GOPERATIONS_H
#define GOPERATIONS_H

#include <stdio.h>
#include "GSeries.h"

typedef float (*operacja)(ciag, rozmiarCiagu);

// funkcja dodawania elementow ciagu
typCiagu Suma(ciag, rozmiarCiagu);

// funkcja mnozenia elementow ciagu
typCiagu Iloczyn(ciag, rozmiarCiagu);

// funkcja wyszukiwania najwiekszego elementu ciagu
typCiagu Max(ciag, rozmiarCiagu); 

// funkcja wykonania zadaniej operacji na ciagu
typCiagu Wykonaj(operacja,ciag,rozmiarCiagu);

// funkcja obliczania sredniej ciagu
typCiagu Srednia(ciag tab, rozmiarCiagu n);


#endif