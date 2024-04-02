#include "Tester.h"
#include <iostream>

Tester::Tester(const std::string& imie, const std::string& nazwisko, int id, bool automatyzujeTesty)
    : imie(imie), nazwisko(nazwisko), id(id), automatyzujeTesty(automatyzujeTesty) {}

Tester::~Tester() {}

void Tester::przedstawSie() const {
    std::cout << "Jestem testerem.\n";
    std::cout << "Mam na imię: " << imie << " " << nazwisko << " i mój numer ID jest: " << id << "\n";
    std::cout << "A odpowiedź na to, czy automatyzuję testy brzmi - " << (automatyzujeTesty ? "tak" : "nie") << "\n";
}

void Tester::ReleaseFromWork() {
    delete this;
}
