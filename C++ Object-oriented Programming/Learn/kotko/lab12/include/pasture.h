#ifndef H_PASTURE
#define H_PASTURE

#include <iostream>
#include <utility>

/// Klasa implementujaca pastwisko
class Pasture{
private:
  double area;
  bool* sheeps;
  int amount;

public:
  /// Domyslny konstruktor zerujacy zmienne
  Pasture() : area(0), sheeps(nullptr), amount(0){};
  /// Konstruktor tworzacy pastwisko o podanym polu i ilosci owiec
  Pasture(double a, int amount) : area(a*a), sheeps(new bool[amount]), amount(amount){
    for(int i = 0; i<amount; i++){
      sheeps[i] = rand()%2;
    }
  }
  /// Destruktor
  ~Pasture(){
    if(sheeps != nullptr){
      delete [] sheeps;
    }
  }
  /// Konstruktor kopiujacy
  Pasture(const Pasture &a): area(a.area), amount(a.amount){
    sheeps = new bool[amount];
    for(int i = 0; i < amount; i++){
      sheeps[i] = a.sheeps[i];
    }
  }
  /// Konstruktor przenoszacy
  Pasture(Pasture &&a){
    amount = std::move(a.amount);
    area = std::move(a.area);
    sheeps = std::exchange(a.sheeps, nullptr);
  }

  /// przeladowanie operatora *=
  Pasture operator *= (const double &a){
    this->area *= a;
    return *this;
  }

  /// przeladowanie operatora =
  Pasture& operator=(const Pasture &a){
    this->area = a.area;
    this->amount = a.amount;
    if(this->sheeps != nullptr){
      delete [] this->sheeps;
    }
    this->sheeps = new bool[this->amount];
    for(int i = 0; i<this->amount; i++){
      this->sheeps[i] = a.sheeps[i];
    }
    return *this;
  }

  /// przeladowanie operatora () porownujacego dwa elementy
  bool operator()(const Pasture &a, const Pasture &b){
    return a.area > b.area;
  }

  /// deklaracja przyjazni z globalnymi operatorami
  friend std::ostream& operator<<(std::ostream& out, const Pasture& a);
  friend Pasture operator+(const Pasture &a, const Pasture &b);
};

/// implementacja globalnego operatora ostream << Pasture
std::ostream& operator<<(std::ostream& out, const Pasture& a){
  out << "area: " << a.area << ", sheeps: ";
  for(int i = 0; i<a.amount; i++){
    out << a.sheeps[i] << " ";
  }
  return out;
}

/// implementacja globalnego operatora Pasture + Pasture
Pasture operator+(const Pasture &a, const Pasture &b){
  Pasture ret;
  ret.area = a.area + b.area;
  ret.amount = a.amount + b.amount;
  ret.sheeps = new bool[ret.amount];
  for(int i = 0; i<a.amount; i++){
    ret.sheeps[i] = a.sheeps[i];
  }
  for(int i = 0; i<b.amount; i++){
    ret.sheeps[a.amount + i] = b.sheeps[i];
  }
  return ret;
}

/// implementacja globalnego operatora double * Pasture
Pasture operator*(const double &a, const Pasture &b){
  Pasture ret = b;
  ret *= a;
  return ret;
}

/// implementacja globalnego operatora Pasture * double
Pasture operator*(const Pasture &b, const double &a){
  Pasture ret = b;
  ret *= a;
  return ret;
}


#endif
