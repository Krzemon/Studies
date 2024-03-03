/*
 * Prosze dopisać kod, dodać nowe pliki students.h i students.cpp, 
 * tak aby program się wykonywał, a wynik jego dzialania 
 * byl taki sam, jak podany na końcu tego pliku.
 * 
 * Prosze napisac funkcje wykonujace operacje na listach zaimplementowanych
 * na tablicach dynamicznych, reprezentujacych listę studentow.
 * Wszystkie tablice przechowują wskaźniki do poszczególnych wartości
 * i są dynamicznie alokowane, dostosując się do liczby wskaźników do elementów
 * które mają być w nich przechowywane.
 * Alokację pamięci można zrealizować za pomocą new albo malloc/calloc
 * Prosze zwrocic uwage na dobre zarządzanie pamięcią.
 * Należy napisać funkcje inicjujące takie listy, dodające elementy oraz kasujące listy.
 * 
 * W tablicy "namesList" przechowywane są wskażniki do pierwszego i drugiego imienia
 * studenta oddzielone jedną spacją.
 * W tablicy "surnamesList" przechowywane są nazwiska studentow.
 * W tablicy "semesterList" przechowywany jest aktualny semestr studiów studenta
 * 
 * UWAGA!
 * Można korzystać z funkcji bibliotecznych (strlen, strcpy)
 * Można również napisać własne funkcje.
 * 
 * Pliku main.cpp, nie wolno modyfikowac.
 * 
 * Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
 * o nazwie Lab03. Program nalezy kompilowac z flagami -Wall -pedantic.

 * Makefile powinien zawierac rowniez reguły: "clean", ktora usuwa pliki
 * obiektowe i plik wykonywalny, "run" - wykonywanie programu oraz "all" (main + run)
 * Rozwiazanie (czyli spakowany katalog z dodanymi plikami, makefile i main.cpp)
 * należy wysłać na UPEL. Nazwa spakowanego katalogu: nazwisko_l3 
 * (same małe litery bez polskich znaków)
 * Proszę wcześniej wywołać make clean!
*/

#include "students.h"

int main()
{
  int numberOfStudents = 0;
  char** namesList = NULL;
  char** surnamesList = NULL;
  int* semesterList = NULL;

  AddStudent(&numberOfStudents, &namesList, &surnamesList, &semesterList, "Adam Klaudiusz","Nowak", 1);
  AddStudent(&numberOfStudents, &namesList, &surnamesList, &semesterList, "Piotr Marek", "Kowalski", 3);
  AddStudent(&numberOfStudents, &namesList, &surnamesList, &semesterList, "Brunon Marcel", "Jankowski", 7);

  std::cout << "\nSame nazwiska:\n";
  PrintListContent (numberOfStudents, surnamesList);

  std::cout << "\nSame semestry:\n";
  PrintListContent (numberOfStudents, semesterList);

  std::cout << "\nImiona i nazwiska:\n";
  PrintListContent (numberOfStudents, namesList,surnamesList);

  std::cout << "\nWszystko:\n";
  PrintListContent (numberOfStudents, namesList, surnamesList, semesterList);
  
  DeleteStudent(&numberOfStudents, &namesList, &surnamesList, &semesterList,0);
  std::cout << "\nPo usunięciu pierwszego:\n";
  
  PrintListContent (numberOfStudents, namesList, surnamesList, semesterList);
  ClearStudents (&numberOfStudents, &namesList, &surnamesList, &semesterList);
  std::cout << "\nPo usunięciu wszystkich:\n";
  PrintListContent (numberOfStudents, namesList, surnamesList, semesterList);
  return 0;
}
/* wynik dzialania programu:
 ./main
Same nazwiska:
Nowak
Kowalski
Jankowski

Same semestry:
1
3
7

Imiona i nazwiska:
Adam Klaudiusz Nowak
Piotr Marek Kowalski
Brunon Marcel Jankowski

Wszystko:
Nowak, Adam Klaudiusz - semestr 1
Kowalski, Piotr Marek - semestr 3
Jankowski, Brunon Marcel - semestr 7

Po usunięciu pierwszego:
Kowalski, Piotr Marek - semestr 3
Jankowski, Brunon Marcel - semestr 7

Po usunięciu wszystkich:

*/
