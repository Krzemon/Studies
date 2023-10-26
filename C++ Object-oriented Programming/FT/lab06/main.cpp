#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Struktura Vector
typedef struct {
    int x, y, z; // Załóżmy, że to są współrzędne wektora
} Vector;

// Struktura Matrix
typedef struct {
    int rows, cols; // Rozmiary macierzy
    int **data;     // Dane macierzy
} Matrix;

// Funkcje do tworzenia i usuwania wektora oraz macierzy
Vector* form_Vector() {
    Vector *v = (Vector*)malloc(sizeof(Vector));
    v->x = v->y = v->z = 0; // Inicjalizacja wartości
    return v;
}

Matrix* form_Matrix(int rows, int cols) {
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    
    m->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = 0; // Inicjalizacja wartości
        }
    }
    
    return m;
}

void delete_Vector(Vector *v) {
    free(v);
}

void delete_Matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

// Funkcja do drukowania wektora
void print_Vector(const Vector *v) {
    printf("[%d, %d, %d]\n", v->x, v->y, v->z);
}

// Funkcja do drukowania macierzy
void print_Matrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Vector *w1 = form_Vector();
    Matrix *m1 = form_Matrix(5, 14);

    printf("To jest napis - funkcja print działa. Działa też dla zmiennych typu bool:\n");
    printf("1\n");

    printf("\nTo jest wektor:\n");
    print_Vector(w1);
    printf("Adres tego wektora to:\n");
    printf("%p\n", (void*)w1);

    printf("\nA to jest macierz:\n");
    print_Matrix(m1);
    printf("Adres tej macierzy to:\n");
    printf("%p\n", (void*)m1);

    delete_Vector(w1);
    delete_Matrix(m1);

    return 0;
}