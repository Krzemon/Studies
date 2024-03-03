#ifndef h_fvectop
#define h_fvectop

#include "fvector.h"

/// Funkcja dodajaca dwa wektory na ktore wskazniki zostaly podane jako argumenty i zwracajaca wskaznik na nowy obiekt
FourVector* AddFourVectors(FourVector *a, FourVector *b);
/// Funkcja dodajaca dwa wektory ktore zostaly podane jako argumenty i zwracajaca wskaznik na nowy obiekt
FourVector* AddFourVectors(FourVector a, FourVector b);
/// Funkcja liczaca iloczyn skalarny dwoch wektorow na ktore wskazniki zostaly podane jako argumenty
double ScalarProduct(FourVector *a, FourVector *b);
/// Funkcja liczaca iloczyn skalarny dwoch wektorow ktore zostaly podane jako argumenty
double ScalarProduct(FourVector a, FourVector b);

#endif
