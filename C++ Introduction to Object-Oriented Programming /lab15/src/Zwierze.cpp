#include "Zwierze.h"


std::ostream& operator <<(std::ostream& os, const Zwierze& zwierze) {
  if( zwierze.getCountry() != nullptr) {
    os << zwierze.getName() << " zyje w " << zwierze.getCountry()->getName();
  }

  return os;
}


std::string Ptak::_my_name = "Ptak";

Ptak::Ptak() : _kraj(_kraj) {}

Ptak::Ptak(Kraj* kraj) : _kraj(kraj) {}

Ptak::~Ptak() {
  std::cout << "Ptak umiera!" << std::endl;
}

void Ptak::wyswietlInformacje() const {
  if (_kraj != nullptr) {
    _kraj->wyswietlInformacje();
  } else {
    std::cout << "Nieokreślony obszar";
  }
}

void Ptak::wydajDzwiek() const {
  std::cout << "Ptak wydaje dźwięk!" << std::endl;
}

// ---------------------------------------------------

std::string Ssak::_my_name = "Ssak";

Ssak::Ssak() : _kraj(nullptr){}

Ssak::~Ssak() {}
// globalny przeciazony operator wypisania na wyjscie

void Ssak::wyswietlInformacje() const {
}

void Ssak::wydajDzwiek() const {
  std::cout << "Ssak wydaje dźwięk!" << std::endl;
}
