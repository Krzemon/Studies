#ifndef MY_LIST_H
#define MY_LIST_H

#include <iostream>

struct Node {
    char* data;
    Node* next;
};

struct MyList {
    Node* head;
    char* name;
};

void init(MyList* list, const char* name);
void print(const MyList* list);
void append(MyList* list, const char* data);
bool empty(const MyList* list);
void replace(MyList* list, const char* oldData, const char* newData);
void insertAfter(MyList* list, const char* oldData, const char* newData);
void removeAfter(MyList* list, const char* data);
void remove(MyList* list, const char* data);
void clear(MyList* list);

#endif // MY_LIST_H