// To jest przykład instrukcji do ćwiczeń - kompletna instrukcja 
// zawsze będzie zawarta w tym miejscu, tj. w pliku main.cpp
//
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Dla ciagu liczb a_1, ... , a_n przez:
// - pary rowne bedziemy rozumiec wszystkie takie dwa kolejne wyrazy ciagu a_i oraz a_{i+1}, takie ze: a_i = a_{i+1}  (dla 1 <= i <= n-1)
// - pary rosnace bedziemy rozumiec wszystkie takie dwa kolejne wyrazy ciagu a_i oraz a_{i+1}, takie ze: a_i < a_{i+1}  (dla 1 <= i <= n-1)
// - pary malejace bedziemy rozumiec wszystkie takie dwa kolejne wyrazy ciagu a_i oraz a_{i+1}, takie ze: a_i > a_{i+1}  (dla 1 <= i <= n-1)
//
// Uwaga: nie należy powielać kodu z klasy bazowej w klasach pochodnych, tylko wykorzystać pracę wykonywaną przez metody klasy bazowej 
// w metodach klas pochodnych (także w odniesieniu do konstruktorów).
// Generalnie należy unikać duplikacji jakiegokolwiek kodu.
// Poziomy dostepu do skladnikow klas powinny byc dobrane zgodnie z zasadami programowania obiektowego (hermetyzacja/ekapsulacja)  
// Staraj się nie powielać tego samego kodu w różnych miejscach. 
// Kazda klasa powinna byc zdefiniowana w oddzielnym pliku h (deklaracje funkcji, klas i metod, ewentualnie takze definicje jesli klasa szablonowa) i cpp (definicje).
//
//
// Pliku main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod)
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz o strukturze takiej jak w zadaniu na UPeL.
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem labNN/ (gdzie NN to nr laboratorum np. lab01)
// * katalog z zadaniem powinien zawierać podkatalog include/
//   w którym muszą znajdować się wszystkie niezbędne pliki nagłówkowe
// * katalog z zadaniem powinien zawierać podkatalog src/
//   w którym muszą znajdować się wszystkie niezbędne pliki z kodem źródłowym
// * katalog z zadaniem powinien zawierać podkatalog build/ 
//   w którym powinien znajdować się tylko i wyłącznie plik Makefile
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/
//   np. tar -czvf lab01.tar.gz lab01/
// * rozpakowanie archiwum: tar -xvf nazwa.tar
// * wszystkie funkcje w plikach *.h powinny być okomentowane - przykład prawidłowej dokumentacji funkcji:
//
// /** @brief Wyszukanie elementu w liscie.
// *
// * Funkcja przeszukuje liste w celu znalezienia podanego elementu.
// *
// * @param[in] list  wskaznik do listy
// * @param[in] c  wartosc szukanego elementu
// * @return wskaznik do pierwszego elementu listy o wartosci c jesli taki element jest w liscie \n
// * NULL jesli lista nie posiada elementu o wartosci c
// */
// slistEl* find(slist* list, char c);


#include <vector>

#include "Statistics.h"
#include "PairStatistics.h"



using namespace std;


int main(int argc, char** argv) 
{
	vector<int> v{3,7,9,7,8,0,2,6,7,3,1,5,3,0,0,4,1,8,9,9};
 
	Statistics s; 
    for (int x : v)
        s(x);
        
	s.Print();
	
	cout << endl;
	
	PairStatistics ps; 
    for (int i = 1; i < v.size(); i++)
        ps(v[i-1], v[i]);
        
	ps.Print();
	
        
	return 0;
}

/** Wynik dzialania programu:
Srednia z wyrazow ciagu: 4.6
Najmniejszy wyraz ciagu: 0
Najwiekszy wyraz ciagu: 9

Liczba par rownych: 2
Liczba par rosnacych: 10
Liczba par malejacych: 7
*/
