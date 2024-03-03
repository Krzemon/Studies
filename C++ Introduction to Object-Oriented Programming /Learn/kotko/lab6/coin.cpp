#include "coin.h"
#include <stdlib.h>
#include <iostream>

int Coin::get_coin_value(){
  switch(this->value){
    case one: return 1;
    case two: return 2;
    case five: return 5;
  }
  return -1;
}

void Coin::print_side_up(){
  std::cout << (this->side == heads?"heads":"tails") << std::endl;
}

void Coin::toss(){
  this->side = rand()%2==0?heads:tails;
}

CoinSide Coin::get_side_up(){
  return this->side;
}
