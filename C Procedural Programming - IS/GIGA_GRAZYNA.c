

//zadanie 1
/*
#include <stdio.h>

void zapiszDoPlikuBinarnego(const char *nazwaPliku, void *tablica, size_t rozmiarElementu, size_t liczbaElementow) {
    FILE *plik = fopen(nazwaPliku, "wb"); // Otwórz plik binarny do zapisu (tryb "wb").

    if (plik == NULL) {
        perror("Błąd otwierania pliku");
        return;
    }

    // Zapisz tablicę do pliku.
    size_t zapisanychBajtow = fwrite(tablica, rozmiarElementu, liczbaElementow, plik);

    if (zapisanychBajtow != liczbaElementow) {
        fprintf(stderr, "Błąd podczas zapisu do pliku\n");
    } else {
        printf("Zapisano pomyślnie do pliku: %s\n", nazwaPliku);
    }

    fclose(plik); // Zamknij plik po zapisie.
}



    int main() {
    // Przykład użycia procedury do zapisu tablicy intów do pliku "dane.bin".
    int tablica[] = {1, 2, 3, 4, 5};
    const char *nazwaPliku = "dane.bin";
    size_t rozmiarElementu = sizeof(int);
    size_t liczbaElementow = sizeof(tablica) / sizeof(tablica[0]);

    zapiszDoPlikuBinarnego(nazwaPliku, tablica, rozmiarElementu, liczbaElementow);

    return 0;}
*/

//zadanie 2
/*
#include <stdio.h>
#include <stdlib.h>

struct point { double x, y, z; char label[4]; } tab2[13] = {};
double *TAB = realloc(NULL, 17 * sizeof(*TAB));

int main() {
    // Możesz teraz używać tab2 i TAB w swoim programie
    // Na przykład:
    
    // Przykład użycia tab2
    tab2[0].x = 1.0;
    tab2[0].y = 2.0;
    tab2[0].z = 3.0;
    snprintf(tab2[0].label, sizeof(tab2[0].label), "ABC");
    
    // Przykład użycia TAB
    TAB[0] = 10.0;
    TAB[1] = 20.0;
    TAB[2] = 30.0;
    
    // Zwolnienie pamięci przy zakończeniu programu
    free(TAB);
    
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

void proc(float **T, int col, int rows_count) {
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.2f ", T[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int col = 5;
    int rows_count = 3;

    // Alokacja dynamicznej tablicy dwuwymiarowej
    float **myArray = (float **)malloc(rows_count * sizeof(float *));
    for (int i = 0; i < rows_count; i++) {
        myArray[i] = (float *)malloc(col * sizeof(float));
    }

    // Inicjalizacja danych
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < col; j++) {
            myArray[i][j] = i * col + j + 1;
        }
    }

    // Wywołanie procedury proc
    proc(myArray, col, rows_count);

    // Zwalnianie pamięci
    for (int i = 0; i < rows_count; i++) {
        free(myArray[i]);
    }
    free(myArray);

    return 0;
}
*/

//zadanie 3
/*
#include <stdio.h>

int count(const void*, const void*);
int max(const void*, const void*);
int min(const void*, const void*);

int main(){
    int results[] = {max(NULL, NULL), min(NULL, NULL), count(NULL, NULL)};
    int (*func_ptrs[])(const void*, const void*) = {max, min, count};
    char *func_names[] = {"max", "min", "count"};
    char func_chars[] = {'c', 'o', 'u', 'n', 't'};
    
    return 0;
}

int count(const void*, const void*){return 0;}
int max(const void*, const void*){return 1;}
int min(const void*, const void*){return -1;}
*/

//zadanie 4
//a
/*
#include <stdio.h>
#include <stdlib.h>

struct point {
    double z, x, y;
    char label[4];
};

// Komparator do sortowania tablicy po polu 'z'
int compare(const void *a, const void *b) {
    const struct point *pointA = (const struct point *)a;
    const struct point *pointB = (const struct point *)b;
    
    if (pointA->z < pointB->z) return -1;
    if (pointA->z > pointB->z) return 1;
    return 0;
}

int main() {
    struct point TAB[10][7];
    double searchValue;

    // Wczytaj liczbę rzeczywistą
    printf("Podaj liczbę rzeczywistą: ");
    scanf("%lf", &searchValue);

    // Sortuj całą tablicę TAB względem pola 'z'
    int rows = 10;
    int columns = 7;
    int totalElements = rows * columns;

    // Sortuj całą tablicę
    qsort(TAB, totalElements, sizeof(struct point), compare);

    // Wyszukaj wartość w posortowanej tablicy
    struct point key;
    key.z = searchValue;
    struct point *result = (struct point *)bsearch(&key, TAB, totalElements, sizeof(struct point), compare);

    if (result != NULL) {
        printf("Wartość %.2lf znajduje się w tablicy.\n", searchValue);
    } else {
        printf("Wartość %.2lf nie została znaleziona w tablicy.\n", searchValue);
    }

    return 0;
}
*/

//b
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {
    double z, x, y;
    char label[4];
};

// Komparator do sortowania tablicy po polu 'label'
int compare(const void *a, const void *b) {
    const struct point *pointA = (const struct point *)a;
    const struct point *pointB = (const struct point *)b;
    
    return strcmp(pointA->label, pointB->label);
}

int main() {
    struct point TAB[10][7];
    char searchString[4];

    // Wczytaj string
    printf("Podaj string do wyszukania: ");
    scanf("%s", searchString);

    // Sortuj tablicę TAB względem pola 'label'
    int rows = 10;
    int columns = 7;
    int totalElements = rows * columns;
    struct point *flatTAB = (struct point *)malloc(totalElements * sizeof(struct point));

    if (flatTAB == NULL) {
        printf("Błąd alokacji pamięci.\n");
        return 1;
    }

    // "Spłaszcz" tablicę TAB do jednowymiarowej
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            flatTAB[k++] = TAB[i][j];
        }
    }

    // Sortuj spłaszczoną tablicę
    qsort(flatTAB, totalElements, sizeof(struct point), compare);

    // Wyszukaj string w posortowanej tablicy
    struct point key;
    strcpy(key.label, searchString);
    struct point *result = (struct point *)bsearch(&key, flatTAB, totalElements, sizeof(struct point), compare);

    if (result != NULL) {
        printf("String '%s' został znaleziony w tablicy.\n", searchString);
    } else {
        printf("String '%s' nie został znaleziony w tablicy.\n", searchString);
    }

    free(flatTAB);
    return 0;
}
*/

//zadanie ?
/*
#include <stdio.h>
int main(){

    enum fruits {APPLE, MANGO, ORANGE=4, BANANA};
    char * fruit_names[]={
    [APPLE] = "Apple",
    [MANGO] = "Mango",
    [ORANGE] = "Orange",
    [BANANA] = "Banana"};
    size_t size = sizeof(fruit_names);
    printf("ilosc elem = %zd", size/sizeof(*fruit_names));
    for(size_t i=0; i<(size/sizeof(*fruit_names));i++){printf("The name of fruit is %s\n", fruit_names[i]);}

    return 0;
}
*/



//zadanie 8
/*

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *removeMax(struct node **head) {
    if (*head == NULL) {
        // Lista jest pusta
        return NULL;
    }

    struct node *prev = NULL;
    struct node *current = *head;
    struct node *maxNode = *head;
    int maxVal = (*head)->val;

    while (current->next != NULL) {
        if (current->next->val > maxVal) {
            maxVal = current->next->val;
            prev = current;
            maxNode = current->next;
        }
        current = current->next;
    }

    if (prev == NULL) {
        // Usuwamy pierwszy element listy
        *head = (*head)->next;
    } else {
        // Usuwamy inny element listy
        prev->next = maxNode->next;
    }

    return maxNode;
}


int main() {
    // Tworzymy przykładową listę
    struct node *head = malloc(sizeof(struct node));
    head->val = 10;
    head->next = malloc(sizeof(struct node));
    head->next->val = 5;
    head->next->next = malloc(sizeof(struct node));
    head->next->next->val = 15;
    head->next->next->next = NULL;

    // Wywołujemy funkcję do usuwania elementu o największej wartości
    struct node *removedNode = removeMax(&head);

    if (removedNode != NULL) {
        printf("Usunięty element o największej wartości: %d\n", removedNode->val);
        free(removedNode);
    } else {
        printf("Lista jest pusta.\n");
    }

    // Zwolniamy pamięć po pozostałych elementach listy
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
*/

//zadanie 9

/*
dane są następujące deklaracje 
#define N 4
#define M 3

int T[N][M] = {1,3,5,8,0,2,7,12,9,4,6,10};
wynik polecenia: printf(" T[0][0]=%d &T[0][0]=%p ", T[0][0], &T[0][0]);
jest następujący: T[0][0]=1 &T[0][0]=0x7ffd260af1d0

Proszę uzupełnić specyfikatory w wywołaniu funkcji printf() oraz wypisać wynik wykonanego polecenia przyjmując sizeof(int)=4 
printf(" %, %, %, %, %, %, %",T[0]+1,T+2,*(T+1), *(T[0]+2),*T, **T+1,*(T+2)+1);

ODPOWIEDZ

    printf("T[0]+1=%p, T+2=%p, *(T+1)=%d, *(T[0]+2)=%d, *T=%d, **T+1=%d, *(T+2)+1=%d\n",
        (void *)(T[0] + 1), (void *)(T + 2), *(T + 1), *(T[0] + 2), **T, *(*T + 1), *(*T + 2) + 1);
*/



//zadanie 10

/*  a
#include <stdio.h>
#define RAZ(a,b) (a)<(b)?(a):(b)

int main(){
    int x=3,y=4,m=RAZ(x++,y++);
    printf("x=%d, y=%d, m=%d\n",x,y,m);
    return 0;
}
*/


#include <stdio.h>
#define DWA(x) 2*x

int main(){
    double m=47/DWA(2);
    printf("m = %f\n", m);
    return 0;
}


/*  c
#include <stdio.h>
#define TRZY(x) printf("%s = %d\n",#x,x)

int main(){
    TRZY (2*2+6);
    return 0;
}

*/






//DRUGI KOLOS

//zadanie 2

/*Proszę zdefiniować funkcję tab_min tak, aby zwracała wskaźnik do najmniejszej wartości z tablicy, która jest jej argumentem. 
Jeżeli jest kilka elementów o tej samej wartości najmniejszej funkcja zwraca wskaźnik do dowolnej z nich*/
/*
#include <stdio.h>

// Deklaracja funkcji tab_min
int *tab_min(int (*arr)[4], int size);

int main() {
    int A[3][4] = {
        {1, 2, 5, 3},
        {3, 4, 9, 1},
        {3, 5, 6, 0}
    };

    // Wywołanie funkcji tab_min i przypisanie wyniku do zmiennej 'min_ptr'
    int *min_ptr = tab_min(A, 3);

    if (min_ptr != NULL) {
        printf("Najmniejsza wartość w tablicy: %d\n", *min_ptr);
    } else {
        printf("Tablica jest pusta.\n");
    }

    return 0;
}

// Implementacja funkcji tab_min
int *tab_min(int (*arr)[4], int size) {
    if (size <= 0) {
        return NULL; // Zabezpieczenie przed pustą tablicą lub niepoprawnym rozmiarem
    }

    int *min_ptr = &arr[0][0]; // Początkowo ustawiamy wskaźnik na pierwszy element tablicy

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] < *min_ptr) {
                min_ptr = &arr[i][j]; // Znaleziono nową najmniejszą wartość, aktualizujemy wskaźnik
            }
        }
    }

    return min_ptr;
}
*/

//UPEL 1
/*
#include <stdio.h>
 char *c[] = {
     "ENTER",
     "NEW",
     "POINT",
     "FIRST"
 };
  char **cp[] = {  c+3, c+2, c+1, c };
  char ***cpp = cp;
 int main(void)
 {
    printf("%s", **++cpp );
    printf("%s ", *--*++cpp+3 );
    printf("%s", *cpp[-2]+3 );
    printf("%s\n", cpp[-1][-1]+1 );
    return(0);
 }
*/


