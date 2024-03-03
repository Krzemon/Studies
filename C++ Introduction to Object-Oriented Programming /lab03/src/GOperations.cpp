#include "GOperations.h"

typCiagu Suma(ciag tab, rozmiarCiagu n){
    typCiagu x;
    for(size_t i = 0; i< n; ++i){
        x += tab.wyrazy[i];
    }
    return x;
}

typCiagu Srednia(ciag tab, rozmiarCiagu n){
    typCiagu x;
    typCiagu y;
    for(size_t i = 0; i< n; ++i){
        x += tab.wyrazy[i];
    }
    y = x/n;
    return y;
}

typCiagu Iloczyn(ciag tab, rozmiarCiagu n){
    typCiagu x = tab.wyrazy[0];
    for(size_t i = 1; i< n; ++i){
        x *= tab.wyrazy[i];
    }
    return x;
}

typCiagu Max(ciag tab, rozmiarCiagu n){
    typCiagu x = tab.wyrazy[0];
    for(size_t i = 1; i< n; ++i){
        if(tab.wyrazy[i] > x){
            x = tab.wyrazy[i];
        }
    }
    return x;
}

float Wykonaj(operacja op,ciag tab,rozmiarCiagu n){
    return op(tab, n);
}