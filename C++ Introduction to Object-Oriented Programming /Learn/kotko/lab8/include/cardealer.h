#ifndef H_CARDEALER
#define H_CARDEALER

#include "car.h"
#include <vector>


/// Klasa implementujaca sprzedawce samochodow
class SubaruDealer{
  private:
    int _income;
    SubaruCar** _cars;
    int _amount;
    int _size;
  public:
    /// Konstruktor tworzacy nowego sprzedawce mogacego w jednym czasie posiadac n samochodow
    SubaruDealer(int n): _cars(new SubaruCar*[n]){
      _size = n;
      _amount = 0;
      _income = 0;
    };
    /// desktruktor czyszczacy pozostala pamiec
    ~SubaruDealer();
    /// funkcja dodajaca samochod do listy samochodow sprzedawcy wraz z dodatkowymi informacjami na temat numeru identyfikacyjnego oraz ceny
    void new_inventory(SubaruCar, int, int);
    /// funkcja zwracajaca wskaznik na samochod o podanym numerze vin
    SubaruCar* show(int vin);
    /// funkcja kasujaca samochod z listy samochodow sprzedawcy oraz dodajaca kwote do jego zarobkow
    void sell(int vin);
    /// funkcja zwracajaca zarobek sprzedawcy
    int get_income();
    /// funkcja zwracajaca zarobki wszystkich sprzedawcow
    static int get_all_dealers_income();
};

#endif
