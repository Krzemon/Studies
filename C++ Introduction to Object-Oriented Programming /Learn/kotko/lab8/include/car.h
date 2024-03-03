#ifndef H_CAR
#define H_CAR

#include <string>

/// Klasa implementujaca samochod marki Subaru zawierajacy model, rok, przebieg, numer identyfikacyjny oraz cene
class SubaruCar{
  private:
    std::string _model;
    int _year;
    int _mileage;
    int _vin;
    int _price;
  public:
    /// konstruktor inicjalizujacy obiekt na podstaie modelu roku i przebiegu
    SubaruCar(std::string model, int year, int mileage);
    /// funkcja zwracajaca nazwe modelu samochodu
    std::string get_model();
    /// funkcja zwracajaca rok produkcji samochodu
    int get_year();
    /// funkcja zwracajaca przebieg samochodu
    int get_mileage();

  friend class SubaruDealer;
};

#endif
