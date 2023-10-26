#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tnode {
    int value;
    struct tnode* next;
};

int i_rand(int,int);
struct tnode* create(int);
void printList(struct tnode*);
void sortList(struct tnode**);

int main(void) {
    srand(time(NULL));
    struct tnode* head = NULL;
    struct tnode* current = NULL;

    for (int i = 1; i <= 10; i++) {
        struct tnode* newNode = create(i_rand(1, 20));
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    printf("Przed sortowaniem:\n");
    printList(head);

    sortList(&head);

    printf("\nPo sortowaniu:\n");
    printList(head);

    current = head;
    while (current != NULL) {
        struct tnode* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

int i_rand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

struct tnode* create(int value) {
    struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode*));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct tnode* head) {
    printf("address\t\tvalue\tnext\n");
    struct tnode* current = head;
    while (current != NULL) {
        printf("%p\t%d\t%p\n", (void*)current, current->value, (void*)current->next);
        current = current->next;
    }
}

void sortList(struct tnode** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct tnode* evenHead = NULL;
    struct tnode* evenTail = NULL;
    struct tnode* oddHead = NULL;
    struct tnode* oddTail = NULL;

    struct tnode* current = *head;

    while (current != NULL) {
        struct tnode* nextNode = current->next;

        if (current->value % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = current;
                evenTail = current;
                evenTail->next = NULL;
            } else {
                evenTail->next = current;
                evenTail = current;
                evenTail->next = NULL;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = current;
                oddTail = current;
                oddTail->next = NULL;
            } else {
                oddTail->next = current;
                oddTail = current;
                oddTail->next = NULL;
            }
        }

        current = nextNode;
    }

    if (evenHead != NULL) {
        *head = evenHead;
        evenTail->next = oddHead;
    } else {
        *head = oddHead;
    }
}