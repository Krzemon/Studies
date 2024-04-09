/*
  Celem zadania jest rozszerzenie jego wersji podstawowej, kopiowalnej polaczonej listy.
  Ważne, by rozwiązanie zostało zaimplementowane w ten sposob jak to było zadane, czyli
  polimorficzność listy jest uzyskana poprzez przechowywanie referencji do danych poprzez 
  wskaźnik typu klasy bazowej dla klas poszczególnych typów: IntData, StringData, itd.
  co sprowadza się dla klasy Node posiadania atrybutu: LData* Node::m_value

  Rozszerzenie obejmuje:
  - dodatkowy typ FloatData
  - funkcjonalność List::find która weryfikuję czy na liście znajduje się element przekazany przez parametr
  - przeciążenie operatora << dla klasy List, z funkcjonalnością konkatencji list
  UWAGA: może się przydać mechanizm przechwytywania wyjątku, np. dla const LData& ld
  try{
      auto ldstr = dynamic_cast<const DerivedClassType&>(ld);
      / ....
    }
    catch(std::bad_cast){
      / ....
    }

 */
#include <iostream>
#include "List.h"
#include "Data.h"

void eqExample(const LData& ld1, const LData& ld2) {
  std::cout << "eqExample: " << ld1 << " == " << ld2 << " => " << ld1.isSame(ld2) << std::endl;
}

int main() {
  std::cout << std::boolalpha;
  List a;
  a.insert(IntData(10), List::Begin);     // List::Begin/End - to jest typ enumerowany
  a.insert(FloatData(11), List::End);     // Nowy typ danych: FloatData
  a.insert(StringData("Hello"),  List::Begin);
  a.insert(IntData(7)).insert(FloatData(0.3)).insert(StringData("WhereAmI")); // Domyślnie wkładamy na koniec
  a.print(); // domyślny argument printa to std::cout
  std::cout << "\n";
  List b(a); 
  b.insert(IntData(99));
  std::cout << "Lista a " << a << std::endl;
  std::cout << "Lista b " << b << std::endl;
  
  eqExample(IntData(1),IntData(1));
  eqExample(IntData(1),StringData("1"));

  bool found = a.find( IntData(7) );  // Zwracamy prawdę lub fałsz w zależności wyniku wyszukiwania
  std::cout << "found in a: " << found << std::endl;
  found = a.find( StringData("Kasia") );
  std::cout << "found in a: " << found << std::endl;

  a << b << b;  // Konkatenacja list. Z listy b dane zostają pzreniesione do listy a, bez kopiowania!
                // Powtórzenie jest celowe.
  std::cout << "Lista a " << a << std::endl;
  std::cout << "Lista b " << b << std::endl;
}
/* wynik
["Hello", 10, 11, 7, 0.3, "WhereAmI"]
Lista a ["Hello", 10, 11, 7, 0.3, "WhereAmI"]
Lista b ["Hello", 10, 11, 7, 0.3, "WhereAmI", 99]
eqExample: 1 == 1 => true
eqExample: 1 == "1" => false
found in a: true
found in a: false
Lista a ["Hello", 10, 11, 7, 0.3, "WhereAmI", "Hello", 10, 11, 7, 0.3, "WhereAmI", 99]
Lista b []
*/
