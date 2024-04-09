#include "List.h"

Node* List::getNode(InsertionMethod method) {
    if (!m_head) {
        return nullptr;
    }
    Node* currentNode = m_head.get();
    if (method == InsertionMethod::Begin) {
        return currentNode;
    }
    while (currentNode->m_next) {
        currentNode = currentNode->m_next.get();
    }
    return currentNode;
}

List::List(const List& other) : m_head(nullptr) {
    if (!other.m_head) {
        return;
    }
    m_head = std::make_unique<Node>(other.m_head->m_value);
    Node* currentOtherNode = other.m_head.get();
    Node* currentNode = m_head.get();
    while (currentOtherNode->m_next) {
        currentNode->m_next = std::make_unique<Node>(currentOtherNode->m_next->m_value);
        currentNode = currentNode->m_next.get();
        currentOtherNode = currentOtherNode->m_next.get();
    }
}

List& List::operator=(const List& other) {
    if (this == &other) {
        return *this;
    }
    m_head.reset();
    if (!other.m_head) {
        return *this;
    }
    m_head = std::make_unique<Node>(other.m_head->m_value);
    Node* currentOtherNode = other.m_head.get();
    Node* currentNode = m_head.get();
    while (currentOtherNode->m_next) {
        currentNode->m_next = std::make_unique<Node>(currentOtherNode->m_next->m_value);
        currentNode = currentNode->m_next.get();
        currentOtherNode = currentOtherNode->m_next.get();
    }
    return *this;
}

List::~List() {}

List& List::insert(const std::shared_ptr<LData>& data, InsertionMethod method) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
    if (!m_head) {
        m_head = std::move(newNode);
        return *this;
    }
    Node* targetNode = getNode(method);
    if (method == InsertionMethod::Begin) {
        newNode->m_next = std::move(m_head);
        m_head = std::move(newNode);
    } else {
        targetNode->m_next = std::move(newNode);
    }
    return *this;
}

void List::print(std::ostream& os) const {
    Node* currentNode = m_head.get();
    while (currentNode) {
        currentNode->m_value->print(os);
        os << " ";
        currentNode = currentNode->m_next.get();
    }
}

bool List::find(const LData& data) const {
    Node* currentNode = m_head.get();
    while (currentNode) {
        if (currentNode->m_value->isSame(data)) {
            return true;
        }
        currentNode = currentNode->m_next.get();
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    list.print(os);
    return os;
}

List& List::operator<<(const List& other) {
    Node* currentNode = other.m_head.get();
    while (currentNode) {
        insert(currentNode->m_value);
        currentNode = currentNode->m_next.get();
    }
    return *this;
}
