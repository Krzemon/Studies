/*
Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się,
a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

Zadaniem będzie zaimplementowanie przez Ciebie macierzy.

Macierz umożliwiać dodawanie, odczytywanie i usuwanie elementów. Klucze (indeksy)
mogą być dowolnymi nieliczbowymi typami, np. std::string.

Wymagania:

  - Zdefiniuj klasę SparseMatrix, która będzie reprezentować macierz.
  - Klasa powinna zawierać odpowiednie metody do dodawania, odczytywania, przenoszenia i usuwania elementów.
  - Przy odczytywaniu elementu zwracaj odpowiednią wartość.
  - Zaimplementuj semantykę const referencji oraz przenoszenie przy zwracaniu obiektu.


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

Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
ani zadnych innych materialow (np. chatboty wbudowane w edytor).

Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp
należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
* archiwum powinno zawierać katalog z zadaniem, np. lab02/
* archiwum nie powinno zawierać katalogu build/

├── CMakeLists.txt
├── Main.cpp
├── include
│   ├── file.h
│   ├── ...
│   └── file_99.h
└── src
    ├── file.cpp
    ├── ...
    └── file_99.cpp

*/




#include <iostream>
#include "SparseMatrix.h"

int main() {
    SparseMatrix matrix_a(5, 5);

    // Przykład dodawania elementów za pomocą metody insert
    matrix_a.insert(0, 0, new int(1)); // .insert(idX,idY,value)
    matrix_a.insert(1, 1, new int(2));
    matrix_a.insert(2, 2, new int(3));
    matrix_a.insert(3, 3, new int(4));
    matrix_a.insert(4, 4, new int(5));

    // Przykład dodawania elementów za pomocą operatora []
    matrix_a.operator[](0)[1] = new int(6); 
    matrix_a[1][2] = new int(7);
    matrix_a[2][3] = new int(8);
    matrix_a[3][4] = new int(9);
    matrix_a[4][0] = new int(10);

    std::cout << "Element at (0,0): " << *matrix_a[0][0] << " \n" << std::endl;
    std::cout << "Element at (1,1): " << *matrix_a[1][1] << " \n" << std::endl;

    // Przykład wyświetlania całej macierzy
    std::cout << "Whole matrix_a: \n" << matrix_a << std::endl;

    SparseMatrix matrix_b(matrix_a);
    matrix_a.reset(3,3);
    std::cout << "After removing element at (3,3) from matrix_a, the matrix_a contains: \n" << matrix_a << std::endl;
    std::cout << "After removing element at (3,3) from matrix_a, the matrix_b contains: \n" << matrix_b  << std::endl;

    SparseMatrix matrix_c = std::move(matrix_a);
    // Usunięcie elementu
    
    std::cout << "After moving matrix_a, to matrix_c, the matrix_c contains:  \n" << matrix_c << std::endl;
    std::cout << "After moving matrix_a, to matrix_c, the matrix_a contains?  \n" << matrix_a << std::endl;


    return 0;
}


/* Expected output:
Element at (0,0): 1 

Element at (1,1): 2 

Whole matrix_a: 
1 6 0 0 0 
0 2 7 0 0 
0 0 3 8 0 
0 0 0 4 9 
10 0 0 0 5 

After removing element at (3,3) from matrix_a, the matrix_a contains: 
1 6 0 0 0 
0 2 7 0 0 
0 0 3 8 0 
0 0 0 0 9 
10 0 0 0 5 

After removing element at (3,3) from matrix_a, the matrix_b contains: 
1 6 0 0 0 
0 2 7 0 0 
0 0 3 8 0 
0 0 0 4 9 
10 0 0 0 5 

After moving matrix_a, to matrix_c, the matrix_c contains:  
1 6 0 0 0 
0 2 7 0 0 
0 0 3 8 0 
0 0 0 0 9 
10 0 0 0 5 

After moving matrix_a, to matrix_c, the matrix_c contains?  

*/