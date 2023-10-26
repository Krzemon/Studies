#ifndef PESEL_H
#define PESEL_H

// Funkcja do walidacji numeru PESEL
bool PeselValidator(const std::string &pesel, int PESEL[11]);

// Funkcja do obliczania sumy kontrolnej numeru PESEL
int getCtrlNumber(const int PESEL[11]);

// Funkcja do uzyskania dnia urodzenia z numeru PESEL
int getDay(const int PESEL[11]);

// Funkcja do uzyskania miesiąca urodzenia z numeru PESEL
int getMonth(const int PESEL[11]);

// Funkcja do uzyskania roku urodzenia z numeru PESEL
int getYear(const int PESEL[11]);

// Funkcja do drukowania numeru PESEL
void printPesel(const int PESEL[11]);

#endif // PESEL_H
