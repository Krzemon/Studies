#include "node.h"
#include "stack.h"


Stack::Stack(Coin &coin){
  last_node = new Node;
  last_node->value = new Coin(coin);
  last_node->prev = nullptr;
}

Stack::~Stack(){
  while(last_node != nullptr){
    Node* p = last_node->prev;
    delete last_node->value;
    delete last_node;
    last_node = p;
  }
}

void Stack::push(Coin c){
  Node* node = new Node;
  node->value = new Coin(c);
  node->prev = last_node;
  last_node = node;
}

Coin* Stack::pop(){
  if(last_node == nullptr){
    return nullptr;
  }
  Coin* coin = last_node->value;
  Node* p = last_node;
  last_node = last_node->prev;
  delete p;
  return coin;
}
