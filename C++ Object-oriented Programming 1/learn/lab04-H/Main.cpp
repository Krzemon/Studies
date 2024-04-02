/*
Proszę dopisać kod, dodać nowe pliki, tak aby program wykonywał się, 
a wynik jego działania był taki sam jak podany na końcu tego pliku.

Zadaniem będzie zaimplementowanie przez Ciebie systemu zarządzania pracownikami. System powinien obsługiwać różne typy pracowników (np.  Manager, Programista, Tester) i umożliwiać dodawanie, odczytywanie i usuwanie pracowników.

Wymagania:

  - Zdefiniuj interfejs IPracownik, który będzie reprezentować pracownika.
      Zwróć uwagę co się powtarza się pomiędzy pracownikami i co powinni więc dziedziczyć. 
  - Zdefiniuj klasy Manager, Programista, Tester, które będą dziedziczyć po IPracownik.
  - Odpowiednie klasy powinny zawierać odpowiednie metody do zarządzania pracownikami.
  - Przy odczytywaniu danych pracownika (przedstawSie()), zwracaj odpowiednie informacje.

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

Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
ani żadnych innych materiałów (np. chatboty wbudowane w edytor).

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. Rozwiązanie (czyli dodane pliki i Main.cpp 
należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
* archiwum powinno zawierać katalog z zadaniem, np. lab02/
* archiwum nie powinno zawierać katalogu build/

├── CMakeLists.txt
├── Main.cpp
├── include
│   ...
│   └── Tester.h
└── src
    ...
    └── Tester.cpp

*/

#include <iostream>
#include <vector>
#include "IPracownik.h"
#include "Manager.h"
#include "Programista.h"
#include "Tester.h"

int main() {
    std::vector<IPracownik*> pracownicy;

    // Przyjmuje imię, nazwisko, id pracownika
    Manager* manager = new Manager("Jakub", "Hajduga", 1);
    // Przyjmuje imię, nazwisko, id pracownika, jezyk programowania w którm pracuje
    Programista* programista = new Programista("Mieczysław", "Kozielski", 2, "C++");
    // Przyjmuje imię, nazwisko, id pracownika, czy automatyzuje testy
    // W drodze wyjatku - jężeli chcecie się zwolnić dozwolone wstawienie swojego imienia i nazwiska. Nie będzie skutkowało to zwolnieniem z zjaęć!
    Tester* tester = new Tester("John", "Doe", 3, false);

    manager->dodajPodwladnego(programista);
    manager->dodajPodwladnego(tester);

    pracownicy.push_back(manager);
    pracownicy.push_back(programista);
    pracownicy.push_back(tester);

    for (IPracownik* pracownik : pracownicy) {
        pracownik->przedstawSie();
    }

    manager->wygenerujRaport();
    manager->zwolnijPracownika(tester);


    // Nie zapomnijcie zwolnić pamięci pozostałych pracowników po zakończeniu działania programu. 
    manager->ReleaseFromWork();


    return 0;
}

// Przerwa na początku outputu dla ułatwienia waszego czytania - nie jest wymagana 
// Spodziewany output
/*

Jestem managerem.
Mam na imię: Jakub Hajduga i mpoim numerem ID jest: 1

Jestem programistą.
Mam na imię: Mieczysław Kozielski i mpoim numerem ID jest: 2
Moim jezykiem programowania jest: C++

Jestem testerem.
Mam na imię: Pablo Picasso i mpoim numerem ID jest: 3
A odpowiedź na to, czy automatyzuję testy brzmi - nie

Generowanie raportu...
Firma zużywa za dużo pamięci na testerów.
Zwalnianie Pamięci Testera.


*/