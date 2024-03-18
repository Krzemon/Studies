// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Zadanie opiera się o implementację abstrakcyjnych klas Obszar i Zwierze, 
// a także ich konkretne implementacje w postaci klas Kontynent, Kraj, Ptak i Ssak. 
// Użyj wirtualnych funkcji, wirtualnego destruktora, 
// a także override i final do oznaczenia odpowiednich funkcji. 
// Klasa Ptak zawiera skłądową typu Kraj jako miejsce życia.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod), oraz powinna być spełniona zasada
// D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab15/
// * archiwum nie powinno zawierać katalogu build/

#include <vector>
#include "Obszar.h"
#include "Zwierze.h"

int main() {
  Kontynent kontynent;
  Kraj kraj("Polska");
  Ptak* orzel = new Ptak(&kraj);
  Ssak* tygrys = new Ssak();

  // Utwórz wektor wskaźników do klas bazowych
  std::vector<Obszar*> obszary;
  obszary.push_back(&kontynent);
  obszary.push_back(&kraj);

  // Utwórz wektor wskaźników do klas bazowych
  std::vector<Zwierze*> zwierzeta;
  zwierzeta.push_back(tygrys);
  zwierzeta.push_back(orzel);

  // Wywołaj funkcje dla obiektów w wektorze
  for (const auto& obszar : obszary) {
      obszar->wyswietlInformacje();
  }

  for (const auto& zwierze : zwierzeta) {
      zwierze->wydajDzwiek();
      std::cout << *zwierze << std::endl; // Ptak żyje w Polska
      delete zwierze;                     // Ptak umiera!
  }
  return 0;
}
/* wynik dzialania programu:
Kontynent 
Kraj Polska
Ssak wydaje dźwięk!

Ptak wydaje dźwięk!
Ptak żyje w Polska
Ptak umiera!
*/
