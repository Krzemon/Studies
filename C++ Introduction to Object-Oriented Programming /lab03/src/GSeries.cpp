#include "GSeries.h"

ciag* CIAGI[MaxCiagow]{};

ciag InicjalizujCiagGeometryczny(rozmiarCiagu n, typCiagu pierwszy, typCiagu iloraz){

    ciag* tab = new ciag{};
    tab->iloraz = iloraz;
    tab->rozmiar = n;

    typCiagu* TAB = new typCiagu[n];
    TAB[0] = pierwszy;

    for(size_t i = 1; i < n; ++i){
        TAB[i] = iloraz * TAB[i-1];
    }

    tab->wyrazy = TAB;
    CIAGI[IleCiagow] = tab;
    ++IleCiagow;
    
    return *tab;
}

void Wypisz(ciag tab, rozmiarCiagu n){
    std::cout << "(";
    for(size_t i = 0; i < n; ++i){
        std::cout << tab.wyrazy[i]<< ", ";
    }
    std::cout << '\b' << '\b' << ')' << std::endl;
}

void UsunCiagi(void){
    for(size_t i=0; i<IleCiagow; ++i){
        delete CIAGI[i]->wyrazy;
        // delete [] zbior_ciagow[i]->wyrazy;
        // delete zbior_ciagow[i];
    }
}
