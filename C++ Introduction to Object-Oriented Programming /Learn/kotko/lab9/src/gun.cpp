#include "gun.h"
#include "bullet.h"

Gun::Gun(Gun& gun){
  _n = gun._n;
  _bullets = new Bullet*[gun._n];
  for(int i = 0; i<_n; i++){
    if(gun._bullets[i] == nullptr){
      _bullets[i] = nullptr;
    }else{
      Bullet::click();
      _bullets[i] = new Bullet(*gun._bullets[i]);
    }
  }
  _caliber = gun._caliber;
  _remaining_bullets = gun._remaining_bullets;
  if(gun._loaded_bullet != nullptr){
    _loaded_bullet = new Bullet(*gun._loaded_bullet);
  }else{
    _loaded_bullet = nullptr;
  }
}
Gun::Gun(Gun&& gun){
  _bullets = gun._bullets;
  _caliber = gun._caliber;
  _remaining_bullets = gun._remaining_bullets;
  _loaded_bullet = gun._loaded_bullet;
  _n = gun._n;

  gun._bullets = nullptr; //new Bullet*[gun._n];
  gun._remaining_bullets = 0;
  gun._loaded_bullet = nullptr;
}

void Gun::load(){
  if(_remaining_bullets == 0){
    mag_empty();
    return;
  }
  _remaining_bullets -= 1;
  _loaded_bullet = _bullets[_remaining_bullets];
  _loaded_bullet->click();
  _bullets[_remaining_bullets] = nullptr;
}

void Gun::pull_trigger(){
  if(_loaded_bullet == nullptr){
    chamb_empty();
    return;
  }
  delete _loaded_bullet;
  _loaded_bullet = nullptr;
  bang();
}
void Gun::pull_trigger(int n){
  for(int i = 0; i<n; i++){
    if(_loaded_bullet == nullptr){
      load();
    }
    if(_loaded_bullet == nullptr){
      chamb_empty();
      continue;
    }
    delete _loaded_bullet;
    _loaded_bullet = nullptr;
    bang();
  }
}

void Gun::new_magazine(){
  for(int i = _remaining_bullets; i < _n; i++){
    _bullets[i] = Bullet::newBullet(_caliber);
  }
  _remaining_bullets = _n;
}
