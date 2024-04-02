#ifndef PROGRAMISTA_H
#define PROGRAMISTA_H

#include "IPracownik.h"

class Programista : public IPracownik {
private:
    std::string imie;
    std::string nazwisko;
    int id;
    std::string jezykProgramowania;

public:
    Programista(const std::string& imie, const std::string& nazwisko, int id, const std::string& jezykProgramowania);
    ~Programista();

    void przedstawSie() const override;
    void ReleaseFromWork() override;
};

#endif // PROGRAMISTA_H
