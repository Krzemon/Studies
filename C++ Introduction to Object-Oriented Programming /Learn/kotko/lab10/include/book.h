#ifndef book_h
#define book_h
#include <string>
using namespace std;

/// enum definiujacy typ ksiazki
enum Genre {thiller = 1, crime = 2, sci_fi = 3, undefined = 4};

/// klasa implementujaca ksiazke
class Book
{
public:
    /// Konstruktor 5-parametrowy
    Book(string title, string author, unsigned short year, Genre genre, unsigned long ISBN)
        : tytul_(title),
          autor_(author),
          rok_(year),
          numer_(ISBN),
          gatunek_(genre)
    {
    }

    /// Funkcja konwersji *Book -> year
    operator unsigned short() const
    {
        return rok_;
    }

    /// Funkcja konwersji *Book -> gatunek
    operator Genre() const
    {
        return gatunek_;
    }

    /// Funkcja konwersji *Book -> numer
    operator unsigned long() const
    {
        return numer_;
    }

    /// Funkcja konwersji *Book -> tytul
    operator string() const
    {
        return tytul_;
    }

    /// Zwraca autora
    string
    get_author()
    {
        return autor_;
    }
    /// konstruktor kopiujacy
    Book(const Book &other);
    /// konstruktor przenoszacy
    Book(Book &&other);

private:
    string tytul_;
    string autor_;
    unsigned short rok_;
    unsigned long numer_;
    Genre gatunek_;
};

#endif
