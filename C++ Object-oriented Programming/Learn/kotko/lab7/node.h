#ifndef H_NODE
#define H_NODE

#include "coin.h"

/// Klasa implemnetujaca element listy jednokierunkowej zawierajacej obiekt monety
class Node {
private:
  Node* prev;
  Coin* value;

  Node();
public:
  /// Funkcja zwracajaca ilosc stworzonych obiektow klasy Node
  static int get_tot_nodes();

  /// deklaracja przyjazni z klasa o nazwie Stack
  friend class Stack;
};

#endif
