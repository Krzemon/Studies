#ifndef OBSZAR_H
#define OBSZAR_H

#include <iostream>
#include <string>

class Zwierze;

class Obszar {
public:
  virtual void wyswietlInformacje() const = 0;  // wirtualna metoda klasy Obszar
};


// klasa Kontynent dziedziczaca po klasie Obszar
class Kontynent : public Obszar {
public:
  void wyswietlInformacje() const override;     // metoda wyswietlajaca informacje kontynent
};


// klasa Kraj dziedziczaca po klasie Obszar
class Kraj : public Obszar {
public:
  Kraj(std::string country = "-None-");         // domyslny konstruktor dla kraju
  void wyswietlInformacje() const override;     // metoda wyswietlajaca informacje kraj
  std::string getName() const {return _name;}   // metoda zwracajaca nazwe kraju

private:
  std::string _name;
};

#endif // OBSZAR_H