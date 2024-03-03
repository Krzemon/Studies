#ifndef H_CIPHER
#define H_CIPHER

#include "mystring.h"
#include "binary.h"
#include "xor.h"

/// Funkcja szyfrujaca.
/// Funkcja zwraca wskaznik do typu char, pod ktorym bedzie zaalokowana 
/// pamiec dla zaszyfrowanego napisu (nalezy pamietac o jej zwolnieniu).
/// Dwa argumenty to MyString'i napisu do zaszyfrowania oraz hasla.
char* Encode(MyString* str, MyString* passwd);

/// Funkcja deszyfrujaca. Wystarczy zaaplikowac operacje XOR na bitach.
/// Ponownie uwaga: zostanie zaalokowana pamiec na napis wskazany przez textdec
/// -- patrz opis funkcji Encode
char* Decode(MyString* str, MyString* passwd);


#endif
