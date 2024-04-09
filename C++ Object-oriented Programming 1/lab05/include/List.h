#pragma once
#include <iostream>
#include <memory>
#include "Data.h"

enum class InsertionMethod { Begin, End };

class Node {
public:
    std::shared_ptr<LData> m_value;
    std::unique_ptr<Node> m_next;
    Node(const std::shared_ptr<LData>& value) : m_value(value), m_next(nullptr) {}
};

class List {
private:
    std::unique_ptr<Node> m_head;
    Node* getNode(InsertionMethod method);
public:
    List() : m_head(nullptr) {}
    List(const List& other);
    List& operator=(const List& other);
    ~List();
    List& insert(const std::shared_ptr<LData>& data, InsertionMethod method = InsertionMethod::End);
    void print(std::ostream& os = std::cout) const;
    bool find(const LData& data) const;
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    List& operator<<(const List& other); // Overloaded << operator for concatenation
};
