/*
Proszę dopisać kod oraz dodać nowe pliki, tak aby program wykonywał się poprawnie, a wynik jego działania był taki sam jak podany na końcu tego pliku.

Zadanie: Symulacja zoo z dziecziczeniem metod virtualnych i polimorfizmem

Celem zadania jest stworzenie systemu symulującego zoo, w którym zwierzęta nie tylko wykonują podstawowe czynności i wchodzą w interakcje z innymi zwierzętami, 
ale także mają unikalne cechy i umiejętności, które można modyfikować i wykorzystywać w różnych kontekstach.

Wymagania:

  - Stworzyć klasę abstrakcyjną Animal z czterema metodami wirtualnymi: makeSound(), eat(), interact() i useSkill().
  - Metoda wirtualna interact(Animal* other), symuluje interakcję między dwoma zwierzętami, natomiast metoda useSkill()  symuluje wykorzystanie unikalnej umiejętności przez zwierzę.
  - Stworzyć klasy Lion, Tiger i Bear, które dziedziczą po klasie Animal i implementują wszystkie metody wirtualne (metodę interact (interakcje powinny być różne w zależności od typu zwierzęcia, z którym dany obiekt wchodzi w interakcję) i metodę useSkill (każda klasa powinna mieć swoją unikalną umiejętność, którą może wykorzystać) )

Pamiętaj, że metody wirtualne w klasie bazowej powinny być oznaczone słowem kluczowym virtual, a w klasie pochodnej powinny być oznaczone override. Powodzenia!

Proszę zadbać o zarządzanie pamięcią.
Pliku Main.cpp nie wolno modyfikować, chyba że w tekście zadania podano inaczej.

Program wyjściowy powinien składać się z czytelnego kodu.
Powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

Zadania oceniane są wg algorytmu: 
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
│   └── Animal.h
└── src
    ...
    └── Animal.cpp


*/
#include <iostream>
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Tiger.h"
#include "Bear.h"

int main() {
    std::vector<Animal*> zoo;

    // Dodaj zwierzęta do zoo
    zoo.push_back(new Lion());
    zoo.push_back(new Tiger());
    zoo.push_back(new Bear());

    // Każde zwierzę wykonuje swoje działania
    for (Animal* animal : zoo) {
        animal->makeSound();
        animal->eat();
        animal->sleep();
    }

    // Zwierzęta wchodzą w interakcje z innymi zwierzętami
    for (Animal* animal1 : zoo) {
        for (Animal* animal2 : zoo) {
            if (animal1 != animal2) {
                animal1->interact(animal2);
            }
        }
    }

    // Zwierzęta wykorzystują swoje unikalne umiejętności
    for (Animal* animal : zoo) {
        animal->useSkill();
    }

    // Usuń zwierzęta
    for (Animal* animal : zoo) {
        delete animal;
    }

    return 0;
}

//Dodatkowe TODO - jak zostanie wam więcej czasu:
/*
Zaproponuj w komentarzu, lub w pliku Main_v2.cpp wersję main(): która wykona to samo z wykorzystaniem wiązania wczesnego a nie późnego. 
*/


// Spodziewany output z zadania:
/*
Lion roars
Lion eats meet

Tiger growls
Tiger eats meet

Bear grunts
Bear eats fish

Lion roars at Tiger
Lion roars at Bear

Tiger stares at Lion
Tiger stares at Bear

Bear grunts at Lion
Bear grunts at Tiger

Lion uses Hyper Voice skill
Tiger uses Flare Blitz skill 
Bear uses Belly Drum skill
*/