#include "GOperations.h"

float Wykonaj(operacja op, ciag dane, rozmiarCiagu rozmiar){
    return (*op)(dane, rozmiar);
}

float Suma(ciag ciag_ds, rozmiarCiagu rozmiar){
    float suma{};

    for(int i=0; i<rozmiar; ++i){
        suma+=ciag_ds.wyrazy[i];
    }

    return suma;
}

float Iloczyn(ciag ciag_di, rozmiarCiagu rozmiar){
    float iloczyn{1};

    for(int i=0; i<rozmiar; ++i){
        iloczyn*=ciag_di.wyrazy[i];
    }

    return iloczyn;
}

float Max(ciag ciag_dm, rozmiarCiagu rozmiar){
    float max=ciag_dm.wyrazy[0];

    for(int i=1; i<rozmiar; ++i){
        if(ciag_dm.wyrazy[i]>max)
            max=ciag_dm.wyrazy[i];
    }

    return max;
}


