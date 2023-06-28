#ifndef INC_9_GENNAIO_2020_ESERCIZIO2_H
#define INC_9_GENNAIO_2020_ESERCIZIO2_H

#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int priority;
    int inf;
    struct elemento *next;
    struct elemento *prev;
};

struct elemento *nuovo_nodo(int inf, int p);
struct elemento *nuova_lista(int n_elem, int p);
void stampa_lista(struct elemento *testa);
void togli_minimi(struct elemento *l1, struct elemento *l2, struct elemento *l3, struct elemento *l4);

#endif //INC_9_GENNAIO_2020_ESERCIZIO2_H
