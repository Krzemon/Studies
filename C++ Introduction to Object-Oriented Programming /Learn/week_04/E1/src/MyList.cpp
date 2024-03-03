#include "MyList.h"
#include <cstring>

void init(MyList* list, const char* name) {
    list->head = nullptr;
    list->name = new char[strlen(name) + 1];
    strcpy(list->name, name);
}

//Od głowy do końca

void print(const MyList* list) {
    std::cout << list->name << ": ";
    Node* current = list->head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


void append(MyList* list, const char* data) {
    Node* newNode = new Node;
    newNode->data = new char[strlen(data) + 1];
    strcpy(newNode->data, data);
    newNode->next = nullptr;

    if (list->head == nullptr) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool empty(const MyList* list) {
    return list->head == nullptr;
}

void replace(MyList* list, const char* oldData, const char* newData) {
    Node* current = list->head;
    while (current != nullptr) {
        if (strcmp(current->data, oldData) == 0) {
            delete[] current->data;
            current->data = new char[strlen(newData) + 1];
            strcpy(current->data, newData);
        }
        current = current->next;
    }
}

void insertAfter(MyList* list, const char* oldData, const char* newData) {
    Node* current = list->head;
    while (current != nullptr) {
        if (strcmp(current->data, oldData) == 0) {
            Node* newNode = new Node;
            newNode->data = new char[strlen(newData) + 1];
            strcpy(newNode->data, newData);
            newNode->next = current->next;
            current->next = newNode;
        }
        current = current->next;
    }
}

void removeAfter(MyList* list, const char* data) {
    Node* current = list->head;
    while (current != nullptr) {
        if (strcmp(current->data, data) == 0) {
            Node* toDelete = current->next;
            if (toDelete != nullptr) {
                current->next = toDelete->next;
                delete[] toDelete->data;
                delete toDelete;
            }
        }
        current = current->next;
    }
}

void remove(MyList* list, const char* data) {
    Node* current = list->head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (strcmp(current->data, data) == 0) {
            if (prev == nullptr) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            delete[] current->data;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void clear(MyList* list) {
    Node* current = list->head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete[] toDelete->data;
        delete toDelete;
    }
    list->head = nullptr;
}