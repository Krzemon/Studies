// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest zaimplementowanie klasu Calculator wraz podstawowym zestawem operatorów.
// Cała logika oraz dodatkowe uwagi zawarte są w funkcji main()
//
// Prosze zadbać o dobre zarzadzanie pamiecia.
// Pliku Main.cpp, nie wolno modyfikowac.
// Struktura propramu powinna być oparta o definicję zawartą w pliku CMakeLists.txt
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab03/
// * archiwum nie powinno zawierać katalogu build/

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
    // UWAGA: obiekt calc zachowuje nową wartość wynikającą z użycia danego operatora!
    calc = 12; // niejawna konwersja!
    std::cout << "calc++: " << calc++ << std::endl;
    std::cout << "Wartosc kalkulatora: " << calc() << std::endl;
    std::cout << "--calc: " << --calc << std::endl;
    std::cout << "calc * 2: " << calc * 2 << std::endl;
    std::cout << "2 * calc: " << 2 * calc << std::endl;

    // Przykładowe użycie operatora () i użycia std::function
    // UWAGA: obiekt calc nie zachowuje zwracanej wartości wynikającej z zadanej funkcji,
    // a domyślnym argumentem dla przekazanej funkcji jest bieżąca wartość obiektu calc

    std::function<int(int)> doubleFunc = doubleValue;
    std::cout << "Podwojona wartosc: " << calc(doubleFunc) << std::endl;

    // Przykładowe użycie przeciążonego operatora ()
    std::cout << "Dodana wartosc: " << calc(addValue, 32) << std::endl;

    return 0;
}

/* wynik
Wartosc kalkulatora: 0
calc++: 12
Wartosc kalkulatora: 13
--calc: 12
calc * 2: 24
2 * calc: 48
Podwojona wartosc: 96
Dodana wartosc: 80
 */
