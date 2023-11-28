#include "fvector.h"
#include "fvectop.h"
#include <cmath>
#include <stdio.h>
#include <iostream>

FourVector* CreateFourVector(double *cords){
    FourVector* ret = new FourVector;
    ret->t = cords[0];
    ret->x = cords[1];
    ret->y = cords[2];
    ret->z = cords[3];
    double sp = ScalarProduct(ret,ret);
    if(sp<0){
        ret->M = -sqrt(-sp);
    }else{
        ret->M = sqrt(sp);
    }
    return ret;
}

void PrintFourVector(FourVector vec){
    PrintFourVector(&vec);
}
void PrintFourVector(FourVector *vec){
    std::cout << "(" << vec->t << "," << vec->x << "," << vec->y << "," << vec->z << ")" << std::endl;
}

void DeleteFourVector(FourVector *vec){
    delete vec;
}
