#include "List.h"

List::List() : head(nullptr) {}

List::List(const List& other) {
    if (other.head) {
        head = std::make_unique<Node>(other.head->data->clone());
        Node *curr = head.get();
        Node *currOther = other.head->next.get();
        while (currOther) {
            curr->next = std::make_unique<Node>(currOther->data->clone());
            curr = curr->next.get();
            currOther = currOther->next.get();
        }
    }
}

List& List::insert(std::unique_ptr<Data> data, Position pos) {
    if (!head) {
        head = std::make_unique<Node>(std::move(data));
    } else {
        if (pos == Begin) {
            std::unique_ptr<Node> newHead = std::make_unique<Node>(std::move(data));
            newHead->next = std::move(head);
            head = std::move(newHead);
        } else {
            Node* temp = head.get();
            while (temp->next) {
                temp = temp->next.get();
            }
            temp->next = std::make_unique<Node>(std::move(data));
        }
    }
    return *this;
}

void List::print() const {
    std::cout << "[";
    Node* temp = head.get();
    while (temp) {
        temp->data->print(std::cout);
        temp = temp->next.get();
        if (temp) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
