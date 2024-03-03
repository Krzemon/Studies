#ifndef H_BINARY
#define H_BINARY

#include "mystring.h"

typedef bool* Binary;

/// Funkcja oblicza reprezentacje binarna napisu MyString
/// i zachowuje ja w przekazanym do funkcji (jako referncja) obiekcie typu Binary.
/// Funkcja zwraca dlugosc otrzymanego ciagu bitow.
unsigned int ObtainBinary(MyString *str, Binary &binary);
/// Funkcja do drukowania reprezentacji binarnej na ekran
void PrintBinary(Binary binary, unsigned int binlength);
/// Funkcja do drukowania reprezentacji binarnej napisu MyString na ekran
void PrintBinary(MyString *str);

#endif
