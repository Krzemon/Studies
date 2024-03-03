#ifndef H_PIGGYBANK
#define H_PIGGYBANK

#include "coin.h"

/// Klasa implementujaca skarbonke o rozmiarze mieszczacym dana ilosc monet
class Piggybank{
  private:
    Coin* coins;
    int size;
    int stored;

  public:
    /// Konstruktor tworzacy przestrzen na monety
    Piggybank(int size);
    /// Destruktor czyszczacy pamiec
    ~Piggybank();
    /// funkcja sluzaca do dodawania monety do skarbonki
    void put_coin(Coin &coin);
    /// funkcja zwracajaca sume wartosci monet w skarbonce
    int get_tot_value();
};

#endif
