#ifndef H_LIBRARY
#define H_LIBRARY

#include "book.h"
#include <string>

/// klasa implementujaca biblioteke z ksiazkami
class Library{
private:
  Book** books;
  int size;
  int stored;
public:
  /// konstruktor tworzacy nowa biblioteke o podanym rozmiarze
  Library(int n): books(new Book*[n]), size(n), stored(0){};
  /// destruktor
  ~Library();
  /// konstrukor kopiujacy
  Library(Library&);
  /// konstruktor przenoszacy
  Library(Library&&);
  /// funkcja dodajaca ksiazke do biblioteki
  void new_book(Book);
  /// funkcja zwracajaca wszystkie ksiazki
  Book** get_books();
  /// funkcja zwracajaca ksiazke o podanym tytule
  Book* get_book(std::string);
  /// funckja zwracajaca ilosc przechowywanych ksiazek
  unsigned int get_n_books();
};

#endif
