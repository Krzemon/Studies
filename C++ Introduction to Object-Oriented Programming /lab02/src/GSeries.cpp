#include "GSeries.h"

#include <iostream>

ciag* zbior_ciagow[MAX_N_CIAGOW]{};

ciag InicjalizujCiagGeometryczny(rozmiarCiagu rozmiar, float iloraz){
    ciag* pNowy_ciag = new ciag();

    pNowy_ciag->rozmiar=rozmiar;
    pNowy_ciag->iloraz=iloraz;

    float* wyrazy=new float[rozmiar];

    wyrazy[0]=1.0;

    for(int i=1; i<rozmiar; ++i){
        wyrazy[i]=wyrazy[i-1]*iloraz;
    }

    pNowy_ciag->wyrazy=wyrazy;

    zbior_ciagow[n_ciagow]=pNowy_ciag;
    n_ciagow++;

    return *pNowy_ciag;
}

void Wypisz(ciag ciag_dw, rozmiarCiagu rozmiar){

    std::cout<<'(';
    for(int i=0; i<rozmiar; ++i){
        std::cout<<ciag_dw.wyrazy[i];

        if(i!=rozmiar-1){
            std::cout<<", ";
        }
    }
    std::cout<<')'<<std::endl;

}

void UsunCiagi(){
    for(int i=0; i<n_ciagow; ++i){
        delete [] zbior_ciagow[i]->wyrazy;
        delete zbior_ciagow[i];
    }

    n_ciagow=0;
}