#include <iostream>
#include <string>
#include "pesel.h"

int main() {
const char* Tpesel[] = {"80022901235", 
                 "81022901232", 
                 "01251213366", 
                 "11323113335",
                 "04422956295",
                  "044229562",
                 };

int PESEL[11]; // tablica, w której będziemy trzymać skonwertowany PESEL
bool valid;
// tablica do konwersji liczby miesiąca na nazwę
const char *monthName[] = {0," stycznia "," lutego ", " marca "," kwietnia "," maja "," czerwca ",
    " lipca "," sierpnia "," wrzesnia ",
    " pazdziernika "," listopada "," grudnia "};
for (int i=0; i < 6; ++i) {
  valid = PeselValidator(Tpesel[i], PESEL); //wykonuje konwersję i zwraca poprawność numeru
  if (valid) {
    std::cout << "PESEL: ";
   printPesel(PESEL);
    std::cout << " Suma kontrolna: " << getCtrlNumber(PESEL) << std::endl;
    std::cout << "Numer PESEL jest prawidlowy\n";
    std::cout << "Data urodzenia: " << getDay(PESEL) 
                                    << monthName[getMonth(PESEL)]
                                    << getYear(PESEL) << std::endl;

  }
  else {
    std::cout << "PESEL: "<< Tpesel[i];
    std::cout << " jest nieprawidlowy\n";
} 
  std::cout << "-----------------------------------------\n";
} 
  return 0;
}

