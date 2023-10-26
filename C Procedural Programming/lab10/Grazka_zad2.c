#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rows = 4;
int cols = 4;

void wypisz_i (int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf ("%4d ", *poczatek++);
    printf ("\n");
return;}

int suma (const int *p, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += p[i];
return sum;}

//komparator dla sortowania pojedynczego wiersza integer'ow
int cmp ( const void *a , const void * b ) {
return *( const int *) a - *( const int *) b ;}

//komparator dla sortowania wzgledem sumy w wierszu - tablica wskazników z podpiętymi wierszami
int cmp_sum_pointers(const void* a, const void* b) {
    const int **aa = a;
    const int **bb = b;
return suma(*aa, cols) - suma(*bb, cols);}

//komparator dla sortowania wzgledem sumy w wierszu - tablica wielowymiarowa" podpieta pod wskaznik
int cmp_sum(const void* a, const void* b) {
    const int *aa = a;
    const int *bb = b;
return suma(aa, cols) - suma(bb, cols);}

//komparator dla wyszukiwania wzgledem sumy w wierszu - tablica wskazników z podpiętymi wierszami
int cmp_pointers_find(const void* a, const void* b) {
    const int *var = a;
    const int **bb = b;
return *var - suma(*bb, cols);}

//komparator dla wyszukiwania wzgledem sumy w wierszu - tablica "wielowymiarowa" podpieta pod wskaznik
int cmp_find(const void* a, const void* b) {
    const int *var = a;
    const int *bv = b;
return *var - suma(bv, cols);}

int main() {
    int i, j;
    srand(time(0));
    int **tab_3 = malloc( rows*sizeof(int*));

    for(i = 0; i <rows; i++)
        tab_3[i] = malloc(cols * sizeof(int));
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            tab_3[i][j] = rand() % 2;

    int **tab_33 = malloc( rows * sizeof(int*));
    tab_33[0] = malloc(cols * rows * sizeof(int));

    for(i = 1; i < rows; i++)
        tab_33[i] = tab_33[i-1] + cols ;
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            tab_33[i][j] = rand() % 2;

    int (*tab_333)[cols] = malloc(cols * rows * sizeof(int));
    for(i = 0; i < rows ; i++)
        for(j = 0; j < cols; j++)
            tab_333[i][j] = rand() % 2;

    //posortować każdy wiersz rosnąco
    for(int i = 0; i < rows; ++i) {
        qsort(tab_3[i], cols, sizeof(int), cmp);
        qsort(tab_33[i], cols, sizeof(int), cmp);
        qsort(tab_333[i], cols, sizeof(int), cmp);
    }
    printf("posortowane w wierszach tab_3\n");
    for(int i = 0; i < rows; ++i)
        wypisz_i(tab_3[i], tab_3[i]+cols);
        printf("\n");
        printf("posortowane w wierszach tab_33\n");
    for(int i = 0; i < rows; ++i)
        wypisz_i(tab_33[i], tab_33[i]+cols);
        printf("\n");
        printf("posortowane w wierszach tab_333\n");
    for(int i = 0; i < rows; ++i)
        wypisz_i(tab_333[i], tab_333[i]+cols);
        printf("\n--------------------------------------------------\n");

    //tab_3 - jest tablica wskazników, a przypiete do elementów tablicy wiersze nie stanowia spójnego obszaru pamieci.
    //Dlatego sortowanie wierszy sprowadza sie do przepinania wskaznkiów (zamiana zawatosci elementów tablicy),czyli do sortowania tablicy wskazników
    qsort(tab_3, rows, sizeof(int*), cmp_sum_pointers);

    //tab_33 - jest tablica wskazników, a przypiete do elementów tablicy wiersze stanowia spójny obszar pamieci.
    //Dlatego sortowanie wierszy mozna by było przeprowadzic tak jak w przyadku tablicy tab_3, ale wtedy elementy tablicy nie sa "przekładane", jedynie wskazniki do nich. 
    //W takiej sytuacji gdybysmy czytali tablice po sortowniu  przy pomocy wskaznika tab_33[0]
    // (for i=0; i < rows*cols; printf (tab_33[0]+i, i= i+1)
    // okazałoby sie ze elementy nie sa posortowane - ich układ jest dokładnie taki jak przed sortowaniem.
    //Aby tego uniknąc nalezy posortowac tablicę, jako tablice przypieta do wskaznika tab_33[0] a wielkosc elementu tablicy
    //ustawic na cols*sizeof(int)
    qsort(tab_33[0], rows, cols*sizeof(int), cmp_sum);

    qsort(tab_333, rows, cols*sizeof(int), cmp_sum);
    printf("\n");
    printf("posortowane wiersze tab_3\n");
    for(int i = 0; i < rows; ++i)
        wypisz_i(tab_3[i], tab_3[i]+cols);
    printf("\n");
    printf("posortowane w wiersze tab_33\n");
    for(int i = 0; i < rows; ++i)
        wypisz_i(tab_33[i], tab_33[i]+cols);
    printf("\n");
    printf("posortowane w wiersze tab_333\n");
    for(int i = 0; i < rows; ++i)
        wypisz_i(tab_333[i], tab_333[i]+cols);
    printf("\n");

    printf("\n---------------szukanie-----------------------------------\n");
    int var;
    printf ("wartosc do znalezienia : ");
    scanf("%d", &var);
    int **w1 = bsearch(&var, tab_3, rows, sizeof(int*), cmp_pointers_find);
    //tab_33 - traktowana jako tablica o elementach cols*sizeof(int) przypieta do wskaznika typu int*
    int *w2 = bsearch(&var, tab_33[0], rows, cols*sizeof(int), cmp_find);
    //tab_33 - traktowana jako tablica wskazników do wierszy
    int **w2a = bsearch(&var, tab_33, rows, sizeof(int*), cmp_pointers_find);
    int (*w3)[cols] = bsearch(&var, tab_333, rows, cols*sizeof(int), cmp_find);
    if(w1 != NULL) {
    printf("tab_3: %d\n", w1-tab_3);
    wypisz_i(*w1, *w1+cols);
    } else printf("tab_3 nie istnieje.\n");
    if(w2 != NULL) {
    printf("tab_33: %d\n", (w2 - tab_33[0])/cols);
    wypisz_i(w2, w2+cols);
    } else printf("tab_33 nie istnieje.\n");
    if(w2a != NULL) {
    printf("tab_33: %d\n", w2a-tab_33);
    wypisz_i(*w2a, *w2a+cols);
    } else printf("tab_33 nie istnieje.\n");
    if(w3 != NULL) {
    printf("tab_333: %d\n", w3-tab_333);
    wypisz_i(*w3, *w3+cols);
    } else printf("tab_333 nie istnieje.\n");

    for(i = 0; i < rows; i++)
    free(tab_3[i]);
    free(tab_3);
    free(tab_33[0]);
    free(tab_33);
    free(tab_333);
return 0;}