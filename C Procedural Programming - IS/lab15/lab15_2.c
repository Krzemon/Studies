#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tnode {
    int value;
    struct tnode* next;
    struct tnode* prev;
};

int i_rand(int min, int max);
struct tnode* create(int value);
void print_list_next(struct tnode* head);
void print_list_prev(struct tnode* head);
struct tnode* add_first(struct tnode* head, struct tnode* el);
struct tnode* add_last(struct tnode* head, struct tnode* el);
struct tnode* del_el_all(struct tnode** head, int var);
struct tnode* del_el_one(struct tnode** head, int var);
void add_sort(struct tnode** head, struct tnode* el);
struct tnode* div_list(struct tnode** head);
void free_list(struct tnode** head);

int main(void) {
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych
    struct tnode* head = NULL;
    struct tnode* current = NULL;

    for (int i = 1; i <= 10; i++) {
        struct tnode* newNode = create(i_rand(1, 20)); // Generowanie losowej wartości od 1 do 20
        head = add_last(head, newNode);
    }

    printf("Lista według next:\n");
    print_list_next(head);

    printf("\nLista według prev:\n");
    print_list_prev(head);

    struct tnode* newElement = create(25);
    head = add_first(head, newElement);

    printf("\nLista po dodaniu elementu na początku:\n");
    print_list_next(head);

    struct tnode* newElement2 = create(30);
    head = add_last(head, newElement2);

    printf("\nLista po dodaniu elementu na końcu:\n");
    print_list_next(head);

    struct tnode* deletedElements = del_el_all(&head, 10);
    printf("\nUsunięte elementy o wartości 10:\n");
    print_list_next(deletedElements);

    printf("\nLista po usunięciu elementów o wartości 10:\n");
    print_list_next(head);

    struct tnode* deletedElement = del_el_one(&head, 25);
    printf("\nUsunięty pierwszy element o wartości 25:\n");
    print_list_next(deletedElement);

    printf("\nLista po usunięciu pierwszego elementu o wartości 25:\n");
    print_list_next(head);

    struct tnode* newElement3 = create(15);
    add_sort(&head, newElement3);

    printf("\nLista po dodaniu elementu w porządku rosnącym:\n");
    print_list_next(head);

    struct tnode* dividedList = div_list(&head);
    printf("\nLista z podziałem na wartości parzyste i nieparzyste:\n");
    printf("Lista parzysta (next):\n");
    print_list_next(head);
    printf("\nLista nieparzysta (prev):\n");
    print_list_prev(dividedList);

    free_list(&head);

    return 0;
}

int i_rand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

struct tnode* create(int value) {
    struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void print_list_next(struct tnode* head) {
    struct tnode* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void print_list_prev(struct tnode* head) {
    struct tnode* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->prev;
    }
    printf("\n");
}

struct tnode* add_first(struct tnode* head, struct tnode* el) {
    if (head == NULL) {
        return el;
    } else {
        el->next = head;
        head->prev = el;
        return el;
    }
}

struct tnode* add_last(struct tnode* head, struct tnode* el) {
    if (head == NULL) {
        return el;
    } else {
        struct tnode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = el;
        el->prev = current;
        return head;
    }
}

struct tnode* del_el_all(struct tnode** head, int var) {
    struct tnode* deletedList = NULL;
    struct tnode* current = *head;
    while (current != NULL) {
        struct tnode* nextNode = current->next;
        if (current->value == var) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            current->next = NULL;
            current->prev = NULL;
            if (deletedList == NULL) {
                deletedList = current;
            } else {
                struct tnode* lastNode = deletedList;
                while (lastNode->next != NULL) {
                    lastNode = lastNode->next;
                }
                lastNode->next = current;
                current->prev = lastNode;
            }
        }
        current = nextNode;
    }
    return deletedList;
}

struct tnode* del_el_one(struct tnode** head, int var) {
    struct tnode* deletedElement = NULL;
    struct tnode* current = *head;
    while (current != NULL) {
        if (current->value == var) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            current->next = NULL;
            current->prev = NULL;
            deletedElement = current;
            break;
        }
        current = current->next;
    }
    return deletedElement;
}

