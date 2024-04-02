#ifndef MANAGER_H
#define MANAGER_H

#include "IPracownik.h"
#include <vector>

class Manager : public IPracownik {
private:
    std::string imie;
    std::string nazwisko;
    int id;
    std::vector<IPracownik*> podwladni;

public:
    Manager(const std::string& imie, const std::string& nazwisko, int id);
    ~Manager();

    void przedstawSie() const override;
    void dodajPodwladnego(IPracownik* podwladny);
    void wygenerujRaport();
    void zwolnijPracownika(IPracownik* pracownik);
    void ReleaseFromWork() override;
};

#endif // MANAGER_H
