#include "cardealer.h"
#include "car.h"
#include <iostream>

int all_income = 0;

void SubaruDealer::new_inventory(SubaruCar car, int vin, int price){
  if(_amount >= _size){
    std::cout << "SubaruDealer: No place for more cars." << std::endl;
    return;
  }
  SubaruCar* clone = new SubaruCar(car);
  clone->_vin = vin;
  clone->_price = price;
  _cars[_amount] = clone;
  _amount += 1;
}

SubaruDealer::~SubaruDealer(){
  for(int i = 0; i<_amount; i++)
    delete _cars[i];
  delete[] _cars;
}

SubaruCar* SubaruDealer::show(int vin){
  for(int i = 0; i<_amount; i++){
    if(_cars[i]->_vin == vin){
      return _cars[i];
    }
  }
  return nullptr;
}

void SubaruDealer::sell(int vin){
  for(int i = 0; i<_amount; i++){
    if(_cars[i]->_vin == vin){
      // znaleziony samochod
      SubaruCar* ret = _cars[i];
      //przesuwanie nastepnych samochodow o 1 miejsce w lewo w tablicy
      for(int j = i+1; j<_size; j++){
        _cars[j-1] = _cars[j];
      }
      // o ostatni wskaznik sie nie martwimy, poniewaz poprzez zmniejszenie 
      // licznika zostanie on nadpisany przy ewentualnym dodawnaiu nowego 
      // samochodu

      // zmniejszanie o jeden licznika samochodow
      _amount -= 1;
      //dodawanie zyskow
      _income += ret->_price;
      all_income += ret->_price;
      //kasowanie samochodu
      delete ret;
      return;
    }
  }
  std::cout << "SubaruDealer: no such car." << std::endl;
}

int SubaruDealer::get_income(){
  return _income;
}

int SubaruDealer::get_all_dealers_income(){
  return all_income;
}
