#include "Node.h"

Node::Node(std::unique_ptr<Data> data) : data(std::move(data)), next(nullptr) {}

