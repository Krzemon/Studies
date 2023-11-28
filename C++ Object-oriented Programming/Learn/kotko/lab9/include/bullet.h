#ifndef H_BULLET
#define H_BULLET

#include <iostream>

/// Klasa implementujaca pocisk, zawiera kaliber pocisku
class Bullet{
private:
  float _caliber;
public:
  /// funkcja zwracajaca kaliber pocisku
  float get_caliber();
  /// funkcja wyswietlajaca "-click- "
  static void click() { std::cout << "-click- "; }
  /// funkcja tworzaca nowy pocisk
  static Bullet* newBullet(float);
};

#endif
