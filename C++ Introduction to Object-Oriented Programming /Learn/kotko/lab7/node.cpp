#include "coin.h"
#include "node.h"

int nodes_created = 0;

Node::Node(){
  nodes_created++;
}

int Node::get_tot_nodes(){
  return nodes_created;
}
