#include "coin.h"
#include "piggybank.h"
#include <iostream>

Piggybank::Piggybank(int size){
  this->size = size;
  this->stored = 0;
  this->coins = new Coin[size];
}
Piggybank::~Piggybank(){
  delete []this->coins;
}
void Piggybank::put_coin(Coin &coin){
  if(this->stored >= this->size){
    std::cout << "Piggybank is full..." << std::endl;
    return;
  }
  this->coins[this->stored] = coin;
  this->stored++;
}
int Piggybank::get_tot_value(){
  int tot = 0;
  for(int i = 0; i < this->stored; i++){
    tot += this->coins[i].get_coin_value();
  }
  return tot;
}
