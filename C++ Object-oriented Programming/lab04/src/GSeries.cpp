#include "GSeries.h"

ciag CIAGI[MaxCiagow]{};

ciag InicjalizujCiagGeometryczny(rozmiarCiagu n, typCiagu pierwszy, typCiagu iloraz){

    ciag tab = new struct ciagg;

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
    
    return tab;
}

void Wypisz(ciag tab, rozmiarCiagu n){
    std::cout << "(";
    for(size_t i = 0; i < n; ++i){
        std::cout << tab->wyrazy[i]<< ", ";
    }
    std::cout << '\b' << '\b' << ')' << std::endl;
}

// void UsunCiagi(void){
//     for(size_t i=0; i<IleCiagow; ++i){
//         // nie zwalniam pamieci na tablice wyrazow ciagow z linii 12 dla kazdego ciagu
//         // delete CIAGI[i]->wyrazy;
//     }
//     // nie zwalniam tablicy adresow ciagow 
//     // delete CIAGI;
// }


void UsunCiagi(void){
    for(size_t i = 0; i < IleCiagow; ++i){
        // Zwolnienie pamięci dla tablicy wyrazów ciągu
        delete[] CIAGI[i]->wyrazy;
        // Zwolnienie pamięci dla struktury ciagg
        delete CIAGI[i];
    }
    // Zerowanie tablicy wskaźników CIAGI
    IleCiagow = 0;
}
