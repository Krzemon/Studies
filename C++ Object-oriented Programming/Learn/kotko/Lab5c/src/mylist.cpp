#include "../include/particle.h"
#include "../include/mylist.h"

/// Inicjalizacja listy.
/// Funkcja tworzy pierwszy wezel listy i zwraca wskaznik
/// do tego wezla.
/// UWAGA: lista tylko zapamietuje wskazniki do istniejacych
/// obiektow! Nie robi kopii obiektow.
ListElem*  InitList(Particle* particle_pt){
    ListElem* el = new ListElem;
    el->particle_pt = particle_pt;
    el->next = NULL;
    return el;
}


/// Funkcja dodajaca element do listy. Lista jest wskazana
/// poprzez podanie dowolnego poprzedniego wezla listy.
void AddToList(ListElem *prev_elem, Particle* particle_pt){
    if(prev_elem == NULL) return;
    //Ustawiamy wskaznik na nastepny element na nowo utworzony element
    FindLastElem(prev_elem)->next = InitList(particle_pt);
}


/// Funkcja znajduje ostatni element listy (wezel) i zwraca
/// do niego wskaznik.
/// Fcja powinna byc uzyta w AddToList.
ListElem *FindLastElem(ListElem *el){
    //Petla wykonuje sie do czasu az nie bedzie nastepnego elementu listy
    // po wykonaniu petli el jest ostatnim elementem listy
    // w przypadku gdy el jest wskaznikiem na NULL petla sie nie wykonuje a funkcja zwraca NULL
    while(el != NULL && el->next != NULL){
        el = el->next;
    }
    return el;
}


/// Funkcja usuwa wezly z pamieci, poczawszy od wskazanego.
/// Wskazanie pierwszego wezla usuwa liste.
void RemoveList(ListElem *init_elem){
    //petla dla kazdego elementu kasuje go i przepisuje nastepny na miejsce aktualnego
    while(init_elem != NULL && init_elem->next != NULL){
        ListElem *t = init_elem->next;
        delete init_elem;
        init_elem = t;
    }
    //kasowanie ostatniego elementu ktorego nie objela petla
    delete init_elem;
}

