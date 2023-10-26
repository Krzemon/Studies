#include <iostream>
#include <cmath>
#include <string>
#include <sstream>


struct Zespolona{
    double re;
    double im;
};

struct WynikRownaniaKwadratowego{
    Zespolona x1;
    Zespolona x2;
};

WynikRownaniaKwadratowego* rownanieKwadratowe(const double& a, const double& b, const double& c){
    WynikRownaniaKwadratowego* wynik = new WynikRownaniaKwadratowego;
    double delta = b*b - 4*a*c;
    if(fabs(delta) == delta){
        wynik->x1.re = (-b + sqrt(delta)) / (2*a);
        wynik->x1.im = 0;
        wynik->x2.re = (-b - sqrt(delta)) / (2*a);
        wynik->x2.im = 0;
        return wynik;
    }
    else{
        wynik->x1.re = (-b) / (2*a);
        wynik->x1.im = sqrt(-delta) / (2*a);
        wynik->x2.re = (-b) / (2*a);
        wynik->x2.im = -sqrt(-delta) / (2*a);
        return wynik;
    }
}

void wypiszWynik(WynikRownaniaKwadratowego* num){
  std::cout<<"Re{z_1} = "<< num->x1.re <<"  "<<"Im{z_1} = "<< num->x1.im << std::endl;
  std::cout<<"Re{z_2} = "<< num->x2.re <<"  "<<"Im{z_2} = "<< num->x2.im << std::endl;
}

bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double d;
    iss >> d;
    return !iss.fail() && iss.eof();
}

bool jestUrojona(Zespolona* num){
  if(num->im != 0) 
    return true;
  else 
    return false;
}

bool jestRzeczywista(Zespolona* num){
  if(num->im == 0) 
    return true;
  else 
    return false;
}

// ********************************************************************************************************************* //
int main(int argc, char* argv[]){
  
    double a=2, b=1, c=1;
    switch(argc){
    case 1: {break;}
    case 4:
        if (isNumber(argv[1]) == false || isNumber(argv[2]) == false || isNumber(argv[3]) == false){
            std::cout << "Argumenty nie są liczbami.\n";
            return 1;
        }
        else{
            a=atof(argv[1]);
            b=atof(argv[2]);
            c=atof(argv[3]);
        }
    break;
    default: 
        std::cout<<"Podaj trzy argumenty.\n";
        return 1;
    }
  
    WynikRownaniaKwadratowego* wynik = rownanieKwadratowe(a, b, c);
    wypiszWynik(wynik);
    std::cout << "Czy liczba z1 jest rzeczywista? " << jestRzeczywista(&(wynik->x1)) << std::endl;
    std::cout << "Czy liczba z1 jest urojona?     " << jestUrojona(&(wynik->x1)) << std::endl;
    std::cout << "Czy liczba z2 jest rzeczywista? " << jestRzeczywista(&(wynik->x2)) << std::endl;
    std::cout << "Czy liczba z2 jest urojona?     " << jestUrojona(&(wynik->x2)) << std::endl;

    delete wynik;
    return 0;
}