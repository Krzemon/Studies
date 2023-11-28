#include "car.h"
#include <string>

SubaruCar::SubaruCar(std::string model, int year, int mileage){
  _model = model;
  _year = year;
  _mileage = mileage;
}

std::string SubaruCar::get_model(){
  return _model;
}

int SubaruCar::get_year(){
  return _year;
}

int SubaruCar::get_mileage(){
  return _mileage;
}
