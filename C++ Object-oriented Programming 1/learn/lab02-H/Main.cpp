/*
Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

Zadaniem będzie zaimplementowanie przez Ciebie słownika, ktość będzie
obsługiwał nieliczbowe indeksy (np. ciągi znaków jako klucze). 

Słownik powinien umożliwiać dodawanie, odczytywanie i usuwanie elementów. Klucze (indeksy) 
mogą być dowolnymi nieliczbowymi typami, np. std::string.

Wymagania:

  - Zdefiniuj klasę Dictionary, która będzie reprezentować słownik.
  - Klasa powinna zawierać odpowiednie metody do dodawania, odczytywania, przenoszenia i usuwania elementów.
  - Przy odczytywaniu elementu o nieliczbowym indeksie, zwracaj odpowiednią wartość.
  - Zaimplementuj semantykę const referencji oraz przenoszenie przy zwracaniu obiektu.

Zadanie to można wykorzystać przy użyciu std::map, std::vector, tablic jak i na wiele innych sposobów.

Proszę zadbać o zarządzanie pamięcią.
Pliku Main.cpp nie wolno modyfikować.

Program wyjściowy powinien składać się z czytelnego kodu.
Powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

Zadania ocenianie są wg algorytmu: 
  - Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów). 
  - Dokumentacja - 1 pkt. 
  - Poprawna kompilacja (bez ostrzeżeń) - 2 pkt. 
  - Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt. 
  - Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt. 

Programy niezgodne z tematem/celem zadania, 
ale kompilujące się (i dające potencjalnie "poprawne" wyjście) będą oceniane na 0 pkt.

Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
ani zadnych innych materialow (np. chatboty wbudowane w edytor).

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp 
należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
* archiwum powinno zawierać katalog z zadaniem, np. lab02/
* archiwum nie powinno zawierać katalogu build/

├── CMakeLists.txt
├── Main.cpp
├── include
│   ├── file.h
│   ├── ...
│   └── file_99.h
└── src
    ├── file.cpp
    ├── ...
    └── file_99.cpp

*/


#include "Dictionary.h"
#include <iostream>

int main() {
    Dictionary dict;
    // Przykład dodawania elementów
    dict.add("apple", 5);
    dict.add("banana", 3);
    dict.add("Answer to the Ultimate Question of Life, the Universe, and Everything", 42);

    std::cout << "Number of apples: " << dict["apple"] << std::endl;
    std::cout << "Number of bananas: " << dict["banana"] << std::endl;

    // Przykład semantyki const referencji
    const Dictionary& constDict = dict;
    std::cout << "Number of apples (const): " << constDict["apple"] << std::endl;
    std::cout << "\nAnswer to the Ultimate Question of Life, the Universe, and Everything: " << 
    constDict["Answer to the Ultimate Question of Life, the Universe, and Everything"] << "\n" << std::endl;

    // Przykład przenoszenia 
    Dictionary newDict = dict.move();
    std::cout << "Number of apples in new dictionary: " << newDict["apple"] << std::endl;
    std::cout << "Number of apples in old dictionary: " << dict["apple"] << std::endl;
    std::cout << "Number of apples (const): " << constDict["apple"] << std::endl;

    // Przykład usuwania
    newDict.remove("apple");

    std::cout << "Number of apples in new dictionary after removal: " << newDict["apple"] << std::endl;

    return 0;
}

/* Expected output:

Number of apples: 5
Number of bananas: 3
Number of apples (const): 5

Answer to the Ultimate Question of Life, the Universe, and Everything: 42

Number of apples in new dictionary: 5
Number of apples in old dictionary: 0
Number of apples (const): 0
Number of apples in new dictionary after removal: 0

*/
