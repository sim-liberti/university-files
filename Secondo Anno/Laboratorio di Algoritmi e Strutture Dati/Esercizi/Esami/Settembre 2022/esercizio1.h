#ifndef SETTEMBRE_2022_ESERCIZIO1_H
#define SETTEMBRE_2022_ESERCIZIO1_H

#include <stdio.h>
#include <stdlib.h>

struct list {
    int index;
    int data;
    struct list *next;
    struct list *prev;
};

struct list *nuovo_nodo(int index, int data);
struct list *nuova_lista(int n_elem);
void stampa_lista(struct list *l_head);
int calcola_media(struct list *l_current);
struct list *sostituisci_media(struct list *l_head);
#endif //SETTEMBRE_2022_ESERCIZIO1_H
