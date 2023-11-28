#ifndef H_STACK
#define H_STACK

#include "node.h"

/// Klasa implementujaca stos oparty o jednokierunkowa liste
class Stack{
private:
  Node* last_node;

public:
  /// Konstruktor tworzacy stos zawierajacy poczatkowy element listy
  Stack(Coin& coin);
  /// Destruktor czyszczacy pamiec zajeta podczas tworzenia stosu
  ~Stack();
  /// Funkcja dodajaca nowa monete na koniec stosu
  void push(Coin coin);
  /// Funkcja zdejmujaca z konca stosu monete
  Coin* pop();
};

#endif
