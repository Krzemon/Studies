#ifndef NODE_H
#define NODE_H

#include "Data.h"
#include <memory>

class Node {
public:
    std::unique_ptr<Data> data;
    std::unique_ptr<Node> next;

    Node(std::unique_ptr<Data> data);
};

#endif // NODE_H
