#include "Obszar.h"

Kraj::Kraj(std::string country) : _name(country) {}

void Kraj::wyswietlInformacje() const{
  std::cout << "Kraj " <<_name << std::endl;
}

void Kontynent::wyswietlInformacje() const{
  std::cout<<"Kontynent"<<std::endl;
}