#ifndef H_GUN
#define H_GUN

#include "bullet.h"

///Klasa implementujaca bron palna posiadajaca magazynek na pociski
class Gun{
private:
  Bullet** _bullets;
  int _remaining_bullets;
  float _caliber;
  Bullet* _loaded_bullet;
  int _n;
public:
  /// Konstruktor tworzacy nowa bron
  Gun(int N, float d):
        _bullets(new Bullet*[N]),
        _caliber(d){
    for(int i = 0; i<N; i++){
      _bullets[i] = Bullet::newBullet(_caliber);
    }
    _remaining_bullets = N;
    _loaded_bullet = nullptr;
    _n = N;
  }
  /// Destruktor czyszczacy pamiec
  ~Gun(){
    for(int i = 0; i < _remaining_bullets; i++)
      delete _bullets[i];
    delete[] _bullets;
    if(_loaded_bullet != nullptr){
      delete _loaded_bullet;
    }
  }
  /// Konstruktor kopiujacy
  Gun(Gun&);
  /// Konstruktor przenoszacy
  Gun(Gun&&);
  /// funkcja implementujaca ladowanie pocisku do komory
  void load();
  /// funkcja implementujaca wystrzelenie pojedynczego pocisku
  void pull_trigger();
  /// funkcja implemnetujaca wystrzelenie podanej ilosci pociskow wraz z przeladowaniem
  void pull_trigger(int);
  /// funkcja wyswietlajaca "Bang!"
  void bang() { std::cout << "\nBang!" << std::endl;}
  /// funkcja wypelniajaca magazynek nowymi pociskami
  void new_magazine();
  /// funkcja wyswietlajaca informacje o pustym magazynku
  void mag_empty() { std::cout << "Gun: Magazine empty." << std::endl; }
  /// funkcja wyswietlajaca informacje o pustej komorze
  void chamb_empty() { std::cout << "Gun: Chamber is empty. Reload." << std::endl; }
};

#endif
