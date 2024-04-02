#include "Manager.h"
#include <iostream>
#include <algorithm>

Manager::Manager(const std::string& imie, const std::string& nazwisko, int id)
    : imie(imie), nazwisko(nazwisko), id(id) {}

Manager::~Manager() {
    for (IPracownik* podwladny : podwladni) {
        delete podwladny;
    }
}

void Manager::przedstawSie() const {
    std::cout << "Jestem managerem.\n";
    std::cout << "Mam na imię: " << imie << " " << nazwisko << " i mój numer ID jest: " << id << "\n";
}

void Manager::dodajPodwladnego(IPracownik* podwladny) {
    podwladni.push_back(podwladny);
}

void Manager::wygenerujRaport() {
    std::cout << "Generowanie raportu...\n";
    std::cout << "Firma zużywa za dużo pamięci na testerów.\n";
}

void Manager::zwolnijPracownika(IPracownik* pracownik) {
    auto it = std::find(podwladni.begin(), podwladni.end(), pracownik);
    if (it != podwladni.end()) {
        podwladni.erase(it);
        delete pracownik;
        std::cout << "Zwalnianie Pamięci Testera.\n";
    }
}

void Manager::ReleaseFromWork() {
    delete this;
}
