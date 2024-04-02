#ifndef TESTER_H
#define TESTER_H

#include "IPracownik.h"

class Tester : public IPracownik {
private:
    std::string imie;
    std::string nazwisko;
    int id;
    bool automatyzujeTesty;

public:
    Tester(const std::string& imie, const std::string& nazwisko, int id, bool automatyzujeTesty);
    ~Tester();

    void przedstawSie() const override;
    void ReleaseFromWork() override;
};

#endif // TESTER_H
