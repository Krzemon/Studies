#include "fvectop.h"
#include "fvector.h"


FourVector* AddFourVectors(FourVector a, FourVector b){
    double d[] = {a.t + b.t, a.x + b.x, a.y + b.y, a.z + b.z};
    return CreateFourVector(d);
}
FourVector* AddFourVectors(FourVector *a, FourVector *b){
    return AddFourVectors(*a, *b);
}

double ScalarProduct(FourVector a, FourVector b){
    return a.t*b.t - a.x*b.x - a.y*b.y - a.z*b.z;
}

double ScalarProduct(FourVector *a, FourVector *b){
    return ScalarProduct(*a, *b);
}
