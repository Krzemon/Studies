#ifndef ZWIERZE_H
#define ZWIERZE_H

#include "Obszar.h"

// klasa po ktorej dzidzicza inne klasy
class Zwierze {
public:
  // wirtualne metody uzywane potem w klasach dziedziczacych
  virtual void wydajDzwiek() const = 0;
  virtual void wyswietlInformacje() const = 0;
  virtual std::string getName() const = 0; 
  virtual Kraj* getCountry() const = 0;

  virtual ~Zwierze() {};
};

// deklaracja przeciazonego operatora wypisania

std::ostream& operator <<(std::ostream& os, const Zwierze& zwierze);

// klasa dziedziczaca po klasie Zwierze
class Ptak : public Zwierze {
public:
  Ptak();      // konstruktor domyslny
  Ptak(Kraj* kraj);      // konstruktor jednoargumentowy
  ~Ptak();               // destruktor

  std::string getName() const {return _my_name;}  // metoda zwracajaca nazwe klasy
  void wydajDzwiek() const override;              // metoda dziedziczona wydaje dzwiek ptaka
  void wyswietlInformacje() const override;       // metoda dziedziczona wyswietla informacje ptaka
    
  Kraj* getCountry() const {return _kraj;}        // metoda zwracajaca kraj

private:
  Kraj* _kraj;
  static std::string _my_name;
};


// klasa dziedziczaca po klasie Zwierze
class Ssak : public Zwierze {
public:
  Ssak();           // konstruktor domyslny
  ~Ssak();          // destruktor

  std::string getName() const {return _my_name;}  // metoda zwracajaca nazwe klasy
  void wydajDzwiek() const override;              // metoda dziedziczona wydaje dzwiek ssaka
  void wyswietlInformacje() const override;       // metoda dziedziczona wyswietla informacje ssaka

  virtual Kraj* getCountry() const override {return _kraj;} ; // metoda zwracajaca kraj

private:
  static std::string _my_name;
  Kraj* _kraj;
};

#endif // ZWIERZE_H