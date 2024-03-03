#include "library.h"
#include <string>
#include <utility>

Library::~Library(){
  for(int i = 0; i< stored; i++)
    delete books[i];
  delete[] books;
}
Library::Library(Library& lib){
  stored = lib.stored;
  size = lib.size;
  books = new Book*[size];
  for(int i = 0; i<stored; i++)
    books[i] = new Book(*lib.books[i]);
}

Library::Library(Library&& lib){
  stored = std::exchange(lib.stored, 0);
  size = std::move(lib.size);
  books = std::exchange(lib.books, nullptr);
}

Book** Library::get_books(){
  return books;
}

Book* Library::get_book(std::string title){
  for(int i = 0; i<stored; i++){
    std::string tytul = *books[i];
    if(tytul == title){
      return books[i];
    }
  }
  return nullptr;
}

void Library::new_book(Book book){
  if(stored >= size){
    return;
  }
  books[stored] = new Book(book);
  stored++;
}

unsigned int Library::get_n_books(){
  return stored;
}
