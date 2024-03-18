// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Zasadniczym celem zadania jest odnalezienie hierarchi klas.
// To znaczy należy znaleźć "część wspolną" pewnych obiektow, ktore wystepuja w temacie.
// Założenia:
// 1) W szczegolnosci w rozwiaząniu moga wystapić tylko dwie implementacje funkcji eval.
// 2) Prosze zwrócić uwage na argumentowość operacji logicznych
// 3) Prosze pamiętac że zachowanie polimorficzne wystepuje tylko z & lub *
// 4) "Logical" nie jest klasą ani strukturą.
//
// Prosze zadbać o dobre zarzadzanie pamiecia.
// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab02/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "Logical.h"

void p1(const OneArg& op) {
  std::cout << "p1  " <<  op.result(true) << std::endl;
}
void p2(const TwoArg& op) {
  std::cout << "p2  " <<  op.result(true, false) << std::endl;
}

int main() {
  std::cout << "OR   " <<  Logical::eval( OR(), false, false ) << std::endl;
  std::cout << "OR   " <<  Logical::eval( OR(), false, true ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, false ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, Logical::eval(NOT(), false) ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), Logical::eval(OR(), true, false ), true ) << std::endl;  

  p1( NOT() );
  p2( OR() );
  p2( AND() );
}
/* wynik
OR   0
OR   1
AND  0
AND  0
AND  1
p1  0
p2  1
p2  0
 */
