#ifndef G_SERIES
#define G_SERIES

typedef long unsigned int rozmiarCiagu;

typedef struct ciag{
    rozmiarCiagu rozmiar;
    float* wyrazy;
    float iloraz;
} ciag;

const int MAX_N_CIAGOW=10;
static int n_ciagow=0;

ciag InicjalizujCiagGeometryczny(rozmiarCiagu rozmiar, float iloraz);

void Wypisz(ciag ciag_dw, rozmiarCiagu rozmiar);

void UsunCiagi();

#endif