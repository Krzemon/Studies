// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Zadanie związane jest z podstawami dziedziczenia wielokrotnego.  
// Klasa PlayerCharacter dziedziczy po GameObject oraz Renderable.
// Wykorzystując RTTI oraz dynamic_cast należy zaimplementować metody
// handleGameObject oraz handleRenderable umieszczone w przestrzeni 
// nazw gutils

// Prosze zadbac o dobre zarzadzanie pamiecia.
// Pliku main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab01/
// * archiwum nie powinno zawierać katalogu build/

#include "PlayerCharacter.h"
#include <memory>


int main() {
  
  std::unique_ptr<GameObject> gameObject = std::make_unique<PlayerCharacter>();
  std::unique_ptr<Renderable> renderableObject = std::make_unique<PlayerCharacter>();

  gutils::handleGameObject(gameObject.get());
  gutils::handleRenderable(renderableObject.get());

  return 0;

}

/* wynik:
Rendering GameObject
PlayerCharacter attacking!
Drawing Renderable
PlayerCharacter attacking!
*/