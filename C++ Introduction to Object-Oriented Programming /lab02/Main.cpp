// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Pliku Main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod).
// UWAGA na temat pragma once oraz podziału programu na pliki:
// #pragma once po prostu blokuje icludowanie danego pliku 
// > tej samej jednostce kompilacji < więcej niż raz, 
// ale nie blokuje includowanie tego samego pliku
// > w różnych jednostkach kompilacji <
// Dlatego, jeśli funkcje są zdefiniowane w nagłówku i nie znajdują się 
// wewnątrz struktury lub klasy (a więc są globalne lub znajdują się w przestrzeni nazw),
// to należy albo zdefiniować je inline, albo podzielić ich definicję na plik .cpp.
//
// Prosze napisac funkcje tworzace i operaujace na ciagach. 
// Należy utworzyć ciągi geometryczne o pierwszym wyrazie 1 i zadanym ilorazie:
// wynik[i] = wynik[i-1]*iloraz;
// Oprocz tego należy obliczyc sume oraz iloczyn wszystkich
// elementow ciagu, a takze znalezc jego najwiekszy element.
//
// Prosze zadbać o dobre zarządzanie pamiecią (valgrind jest pomocny).
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum nie powinno zawierać katalogu build/
// * tworzenie archiwum: tar -czvf nazwa.tar.gz katalog/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.

#include "GSeries.h"
#include "GOperations.h"

int main ()
{
  const rozmiarCiagu rozmiar = 4;
  const float iloraz = 2;
  
  // pierwszy element ciagu to 1
  const ciag geometryczny = InicjalizujCiagGeometryczny (rozmiar, iloraz);
  Wypisz(geometryczny, rozmiar);
  
  const ciag geometryczny2 = InicjalizujCiagGeometryczny (6, 3.);
  Wypisz(geometryczny2, 6);

  printf("Suma: %.2f\n",Suma(geometryczny, rozmiar));
  
  const char* op_nazwa [] = {"Suma", "Iloczyn", "Max"};
  operacja op [] = {Suma, Iloczyn, Max};

  const int ileOperacji = sizeof(op)/sizeof(operacja);
  for (int i = 0; i < ileOperacji; ++i)
    printf("%s: %.2f\n",op_nazwa[i], Wykonaj(op[i],geometryczny2, 6));

  UsunCiagi();
}
/* wynik dzialania programu:
(1, 2, 4, 8)

(1, 3, 9, 27, 81, 243)

Suma: 15.00

Suma: 364.00

Iloczyn: 14348907.00

Max: 243.00
*/
