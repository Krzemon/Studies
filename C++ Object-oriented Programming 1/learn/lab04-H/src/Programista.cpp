#include "Programista.h"
#include <iostream>

Programista::Programista(const std::string& imie, const std::string& nazwisko, int id, const std::string& jezykProgramowania)
    : imie(imie), nazwisko(nazwisko), id(id), jezykProgramowania(jezykProgramowania) {}

Programista::~Programista() {}

void Programista::przedstawSie() const {
    std::cout << "Jestem programistą.\n";
    std::cout << "Mam na imię: " << imie << " " << nazwisko << " i mój numer ID jest: " << id << "\n";
    std::cout << "Moim jezykiem programowania jest: " << jezykProgramowania << "\n";
}

void Programista::ReleaseFromWork() {
    delete this;
}
