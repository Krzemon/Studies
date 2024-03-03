#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

static int N = 1e7;
static int DISPLAY_PRESITION = 7;

double uniform() {
  return (double)rand() / RAND_MAX;
}

double Bernoulli(double p) {
  if (uniform() <= p) 
    return 1;
  else 
    return 0;
}

double Gauss() {
  double U1 = uniform();
  double U2 = uniform();
  return std::sqrt(-2 * std::log(U1)) * std::cos(2 * M_PI * U2);
}


void toFile(std::ofstream &file, int k, double rela, double rela_var)
{
  file << std::fixed << std::setprecision(DISPLAY_PRESITION);
  file << k << '\t' << rela << '\t' << rela_var << std::endl;
}


void parametres(double p, double EX, double EXsquare, double var, std::ofstream &file) {

  int k = 2;
  double x;


  
  for (int i = 1; i < N+1; ++i) {
  x = Bernoulli(p);
  EX += x;
  EXsquare += (x * x);

  if (i == std::pow(10,k)) {
    EX /= i;
    EXsquare /= i;
    var = (EXsquare - EX * EX) / i;

    
    double relative_EX = std::abs(EX - p) / p;
    double relative_var = std::abs(var - p * (1 - p)) / (p * (1 - p));

    toFile(file, k, relative_EX, relative_var);
    ++k;



    // file << std::endl << std::endl;
  }
  }
}


int main() {

  double tab[]  = {0.1, 0.5, 0.9};

  double  X1,X2,X3;
  double EXsquare1,EXsquare2,EXsquare3;
  double var1,var2,var3;

  std::ofstream file_p01("../data/p01.dat", std::ios::out);
  std::ofstream file_p05("../data/p05.dat", std::ios::out);
  std::ofstream file_p09("../data/p09.dat", std::ios::out);

  parametres(tab[0], X1, EXsquare1, var1, file_p01);
  parametres(tab[1], X2, EXsquare2, var2, file_p05);
  parametres(tab[2], X3, EXsquare3, var3, file_p09);




  return 0;
}


