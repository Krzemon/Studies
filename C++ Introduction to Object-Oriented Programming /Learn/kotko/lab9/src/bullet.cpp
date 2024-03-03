#include "bullet.h"
#include <iostream>

Bullet* Bullet::newBullet(float _caliber){
  click();
  Bullet* b = new Bullet();
  b->_caliber = _caliber;
  return b;
}
float Bullet::get_caliber(){
  return _caliber;
}
