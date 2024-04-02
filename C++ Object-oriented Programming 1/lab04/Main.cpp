// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Zadanie związane jest z podstawami dziedziczenia wielokrotnego.  
// W hierarchii wystepuja 4 klasy. Należy poprawnie odwzorowac zależnosci między nimi.
// UWAGA: Operator << zachowuje sie jak, wirtualna metoda, nalezy to rozwiązac przez przekierowania
//        jego funkcjonalnosci do wirtualnej metody.

// Prosze zadbac o dobre zarzadzanie pamiecia.
// Pliku main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab04/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "Person.h"
#include "Faculty.h"
#include "Grade.h"
#include "Student.h"

int main() {
  {
    Person m("Jennifer"); // arg: name
    std::cout << m  << std::endl;
  }

  {
    Student* s = new Student("Jennifer",1334);  // arg: name, id
    Person *x  = s;  
    std::cout << *x << std::endl;
    delete x;
  }
  
  {
    Faculty* l = new Faculty("Jennifer","Physics");  // arg: name, spec
    const Person* x  = l;  
    std::cout << "Faculty: "  << *x << std::endl;
    delete x;
  }

  { // zakres z wielokrotnym dziedziczeniem...
    Grade* k = new Grade("Jennifer",1334,"Physics",5.0); // arg: name, id, spec, value
    Student* s = k;
    Faculty* l = k; l = k = nullptr;
    std::cout << *s << std::endl;    
    delete s;    
  }
}

/* wynik:
name (person): Jennifer
~Jennifer (person)
name (person): Jennifer, id (student): 1334
~1334 (student)
~Jennifer (person)
Faculty: name (person): Jennifer, spec (faculty): Physics
~Physics (faculty)
~Jennifer (person)
As a Student: name (person): Jennifer, id (student): 1334
As a Faculty: name (person): Jennifer, spec (faculty): Physics
Grade value (grade): 5
~5 (grade)
~Physics (faculty)
~1334 (student)
~Jennifer (person
*/