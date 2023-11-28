// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny 
// i dobrze napisany kod, bez powielania kodu - D.R.Y)
//
// Prosze napisac funkcje tworzace i operaujace na ciagach. 
// Należy utworzyć ciągi geometryczne o pierwszym wyrazie podanym jako argument i zadanym ilorazie:
// wynik[i] = wynik[i-1]*iloraz;
// Oprocz tego należy obliczyc sume oraz średnią arytmetyczną wszystkich elementów,
// a alokacja i dealokacja pamięci wykonywana jest za pomocą new / delete
//
// Zadanie zasadniczo jest kontynuacja pracy z poprzedniego tygodnia!
// UWAGA: W tym zadaniu należy POPEŁNIAĆ ŚWIADOME BŁĘDY związana z zarządzaniem pamięci;
// Warunkiem zadania jest implementacja poprawnych oraz błednych instrukcji z tym zwiazanych
// -> każdy "case" proszę odpowiednio pokryć odpowiednim komentarzem w kodzie źródłowym,
// oznaczając kolejne miejsca wystąpienia błedu jako: [BUG] 
// 
// Proszę zdefiniować w CMakeLists.txt odpowiednie definicje zmiennej LOOP_1 oraz LOOP_2
// tak aby program kompilował się i wykonywał w zależności od ich wartości, które
// odpowiednio możemy modyfikować za pomocą wykonania cmake:
// cmake ../ -DLP_1=0 -> tożsame z camke ../
// cmake ../ -DLP_1=1
// analogicznie dla LP_2
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL jako archiwum tar.gz
// UWAGA:
// * pliku Main.cpp w końcowym rozwiazaniu powinien być nie zmieniony
// * archiwum tar.gz nie powinno zawierać katalogu build/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.

#include "GSeries.h"
#include "GSeries.h"
#include "GOperations.h"
#include "GOperations.h" // To nie pomyłka, ponowne include
#include <chrono>

using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>; 
time_point start(){
  return std::chrono::high_resolution_clock::now();
}
void stop(const std::string& name, const time_point& start){
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Czas wykonania " << name << ": "
         << duration.count() << " mikrosekund" << std::endl;
}

int main (){
  auto _start{start()};
  UsunCiagi();
  if(LOOP_1){
    auto _start{start()};
    const rozmiarCiagu rozmiar = 10e5;
    const float iloraz = 1.00001;
    //                  docs: InicjalizujCiagGeometryczny(rozmiar, pierwszy, iloraz);
    const ciag geometryczny = InicjalizujCiagGeometryczny (rozmiar, 0.00001, iloraz);
    const char* op_nazwa [] = {"Suma", "Srednia"};
    operacja op [] = {Suma, Srednia};
    const int ileOperacji = sizeof(op)/sizeof(operacja);
    for (int i = 0; i < ileOperacji; ++i)
      std::cout << op_nazwa[i] << ": " << Wykonaj(op[i],geometryczny, rozmiar) <<std::endl;
    UsunCiagi();
    stop("LOOP_1",_start);
  }
  if(LOOP_2){
    auto _start{start()};
    ciag geometryczny = nullptr;
    for (int i = 1; i < 5; ++i){
      geometryczny = InicjalizujCiagGeometryczny (i, i, 2);
      Wypisz(geometryczny, i);
    }
    stop("LOOP_2",_start);
  }
  UsunCiagi();
  stop("main",_start);
}
/* wynik dzialania programu uwzględniajac LOOP_1 oraz _2 (oczywiście wartości czasowe bedą różne)
Suma: 22292.6
Srednia: 0.0222926
Czas wykonania LOOP_1: 7988 mikrosekund
(1)
(2, 4)
(3, 6, 12)
(4, 8, 16, 32)
Czas wykonania LOOP_2: 82 mikrosekund
Czas wykonania main: 8114 mikrosekund
*/
