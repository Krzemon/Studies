#ifndef G_OPERATIONS
#define G_OPERATIONS

#include "GSeries.h"

#include <cstdio>

typedef float (*operacja)(ciag, rozmiarCiagu);

float Wykonaj(operacja op, ciag dane, rozmiarCiagu rozmiar);

float Suma(ciag ciag_ds, rozmiarCiagu rozmiar);
float Iloczyn(ciag ciag_di, rozmiarCiagu rozmiar);
float Max(ciag ciag_dm, rozmiarCiagu rozmiar);


#endif