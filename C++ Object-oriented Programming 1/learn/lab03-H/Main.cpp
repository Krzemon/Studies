/*
Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

Program ma za zadanie demonstrację wykorzystania klasy `Calculator`, która reprezentuje prosty kalkulator. Klasa ta implementuje operatory przypisania, inkrementacji, dekrementacji, mnożenia, oraz operator wywołania funkcji. Oprócz tego, klasa obsługuje także funkcje wykorzystujące obiekt `std::function`.

1. Klasa `Calculator` powinna posiadać następujące operatory:
- Przypisania (`=`), inkrementacji (`++`), dekrementacji (`--`), mnożenia (`*`), oraz dostępu do wskaźnika (`->`).
- Operator nawiasów `()` przeciążony w trzech wersjach:
    - Jeden argument typu `std::function<int(int)>`, który pozwala na wywołanie funkcji na wartości przechowywanej w obiekcie `Calculator`.
    - Dwa argumenty: `std::function<int(int, int)>` oraz `int`, który pozwala na przekazanie dodatkowych argumentów do wywołanej funkcji.
    - Trzy argumenty: `std::function<int(int, int)>` oraz `int`, `int` oraz `int`, które pozwala na przekazanie dodatkowych argumentów do wywołanej funkcji. 

2. Klasa `Calculator` powinna posiadać metody konstruktora:
    - Bezargumentowy, który ustawia wartość kalkulatora na zero.

3. Klasa `Calculator` powinna umożliwiać wypisywanie wartości kalkulatora na standardowe wyjście za pomocą przeciążonego operatora strumienia wyjścia `<<`.

4. Wszystkie operatory oraz metody powinny być zaimplementowane w pliku `Calculator.h` oraz `Calculator.cpp`.

5. Przy tworzeniu klasy należy zadbać o odpowiednie zarządzanie pamięcią i unikanie wycieków pamięci.

6. Kod powinien być czytelny, dobrze skomentowany oraz zgodny z zasadami programowania obiektowego.

7. Program wyjściowy powinien być poprawnie skompilowany (bez ostrzeżeń) i działać zgodnie z oczekiwaniami.


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


#include <iostream>
#include <functional>
#include "Calculator.h"

// Przykładowa funkcja
int addValue(int x, int y) {
    return x + y;
}
int doubleValue(int x) {
    return 2 * x;
}

int main() {
    Calculator calc;

    std::cout << "Wartosc kalkulatora: " << calc() << std::endl;

    // Przykładowe użycie operatorów
    calc = 10;
    std::cout << "Wartosc kalkulatora: " << calc() << std::endl;
    std::cout << "++calc: " << ++calc << std::endl;
    std::cout << "--calc: " << --calc << std::endl;
    std::cout << "calc * 2: " << calc * 2 << std::endl;

    // Przykładowe użycie operatora () i użycia std::function
    std::function<int(int, int)> addFunc = [](int a, int b) { return a + b; };
    std::cout << "add(3, 5): " << calc(addFunc, 3, 5) << std::endl;

    // Przykładowe użycie przeciążonego operatora ()
    std::function<int(int)> doubleFunc = doubleValue;
    std::cout << "Double value: " << calc(doubleFunc) << std::endl;

    // Przykładowe użycie przeciążonego operatora ()
    std::function<int(int, int)> addToStoredFunc = addValue;
    std::cout << "Add value: " << calc(addFunc, 32) << std::endl;


    return 0;
}

/*

Wartosc kalkulatora: 0
Wartosc kalkulatora: 10
++calc: 11
--calc: 10
calc * 2: 20
add(3, 5): 8
Double value: 20
Add value: 42

*/
