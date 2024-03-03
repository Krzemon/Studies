#ifndef H_COIN
#define H_COIN

/// Strony monety
enum CoinSide{
  heads, tails
};

/// Wartosci monet
enum CoinValue{
  one,two,five
};

/// Klasa implementujaca monete posiadajaca wartosc i strone
class Coin{
  private:
    CoinValue value;
    CoinSide side;

  public:
    /// Konstruktor inicjalizujacy monete o domyslnej wartosci 1PLN
    Coin(){
      this->value = one;
      toss();
    }
    /// Konstruktor inizjalizujacy monete o podanej wartosci
    Coin(CoinValue value){
      this->value = value;
      toss();
    }
    /// Funkcja zwracajaca wartosc liczbowa monety
    int get_coin_value();
    /// Funkcja wyswietlajaca strone monety
    void print_side_up();
    /// Funkcja zwracajaca strone monety
    CoinSide get_side_up();
    /// Funkcja losujaca strone monety
    void toss();
};

#endif
