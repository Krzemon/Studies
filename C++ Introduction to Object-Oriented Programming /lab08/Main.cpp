// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod, bez powielania kodu - D.R.Y)
//
// Celem zadania jest refaktoryzacja i rozszerzenie klas Point3D oraz VPointCloud z poprzednich zajęć.
// Kolejne funkcjonalności zos  tały opisane w ramach funkcji main()
//
// Przy wykonaniu zadania nie wolno korzystać z internetu z wyjątkiem linków podanych wyżej,
// notatek, ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz CMakeLists.txt, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL jako archiwum tar.gz
// UWAGA:
// * pliku Main.cpp w końcowym rozwiazaniu powinien być nie zmieniony
// * archiwum tar.gz nie powinno zawierać katalogu build/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.

#include "PointCloud.h"

int main() {

  const Point3D myPoint3D_1({1.2, 3.4, 5.6});
  myPoint3D_1.displayCoordinates();

  // do manipulacji precyzją wypisywania przyda się z nagłówka <iomanip>
  // std::cout << std::fixed; oraz std::setprecision(n)
  Point3D::DISPLAY_PRESITION = 2;

  Point3D myPoint3D_2;      // delegacja ctr'a
  myPoint3D_2.displayCoordinates();

  Point3D myPoint3D_3(3.0); // delegacja ctr'a
  myPoint3D_3.displayCoordinates();

  std::cout << "Chmura punktów 1:\n";
  VPointCloud myVPointCloud_1; // wersja z std::vector
  myVPointCloud_1.addPoint(new Point3D({2.0, 3.0, 4.0})); // przechowujemy wskaźniki na Point3D
  myVPointCloud_1.addPoint({4.0, 3.0, 2.0});
  myVPointCloud_1.displayPoints();

  std::cout << "Chmura punktów 2:\n";
  VPointCloud myVPointCloud_2;
  // VPointCloud::getCopyPoint(i) zwraca ptr na kopię punktu przechowywanego pod indeksem = i
  myVPointCloud_2.addPoint(myVPointCloud_1.getCopyPoint(0));
  myVPointCloud_2.displayPoints();

  std::cout << "Dodawanie chmur punktów :-)\n";
  std::cout << "Chmura 1 + 2:\n";
  myVPointCloud_1.add(myVPointCloud_2);
  myVPointCloud_1.displayPoints();

  std::cout << "Chmura 2 + 2:\n"; // tak to nie pomyłka! W tym przypadku nic nie jest kopiowane!
  myVPointCloud_2.add(myVPointCloud_2);
  myVPointCloud_2.displayPoints();

  std::cout << "Przenoszenie punktów między obiektami, 2 -> 3:\n";
  VPointCloud myVPointCloud_3(std::move(myVPointCloud_2));
  myVPointCloud_3.displayPoints();

  return 0;
}

/* wynik dzialania
(1.2, 3.4, 5.6)
(0.00, 0.00, 0.00)
(3.00, 3.00, 3.00)
Chmura punktów 1:
(2.00, 3.00, 4.00)
(4.00, 3.00, 2.00)
Chmura punktów 2:
(2.00, 3.00, 4.00)
Dodawanie chmur punktów :-)
Chmura 1 + 2:
(2.00, 3.00, 4.00)
(4.00, 3.00, 2.00)
(2.00, 3.00, 4.00)
Chmura 2 + 2:
(2.00, 3.00, 4.00)
Przenoszenie punktów między obiektami, 2 -> 3:
(2.00, 3.00, 4.00)
 */
