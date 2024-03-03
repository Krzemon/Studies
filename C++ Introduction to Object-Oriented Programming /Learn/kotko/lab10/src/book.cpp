#include "book.h"

Book::Book(const Book &other)
{
    tytul_ = other.tytul_;
    autor_ = other.autor_;
    rok_ = other.rok_;
    numer_ = other.numer_;
    gatunek_ = other.gatunek_;
}

Book::Book(Book &&other)
{
    tytul_ = move(other.tytul_);
    autor_ = move(other.autor_);
    rok_ = move(other.rok_);
    numer_ = move(other.numer_);
    gatunek_ = move(other.gatunek_);
}

