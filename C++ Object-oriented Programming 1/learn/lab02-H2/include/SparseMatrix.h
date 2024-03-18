#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include<iostream>
#include<string>


class SparseMatrix
{


private:

  int Rows;
  int Columns;
  int ***Matrix;

public:



  SparseMatrix();

  //Konstruktor 
  // rows - ilosc wierszy
  // columns - ilosc kolumn macierzy 
  SparseMatrix (int rows, int columns);

  //other -inny obiekt klasy SparseMatrix;
  SparseMatrix (const SparseMatrix& other);


  // kopiujacy operator przypisania
  SparseMatrix & operator= (const SparseMatrix & other);

  //konstruktor przenoszacy
  SparseMatrix(SparseMatrix&& other);

  //przenoszacy operator przypisania
   SparseMatrix & operator=(SparseMatrix&& other);


  //Destruktor
  ~SparseMatrix();

  //Funkcja umieszcza przekazywany wskaznik value na miejscu w macierzy o podanym wierszu i kolumnie
  void insert(int row, int col, int *value);

  //Funkcja "zeruje" macierz w miejscu o podanym wierszu i kolumnie
  void reset(int row, int col);

  //operator [] daje dostep do macierzy;
    int** operator[](int index);


 friend std::ostream& operator<<(std::ostream& os, const SparseMatrix& object);
};





#endif
