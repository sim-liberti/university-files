//
// Created by simli on 6/18/2023.
//

#ifndef INC_13_02_2006_ESERCIZIO2_H
#define INC_13_02_2006_ESERCIZIO2_H

#include <stdio.h>
#include <stdlib.h>

struct elemento {
    struct elemento *prev;
    int inf;
    struct elemento *next;
};

struct elemento *nuovo_nodo(int inf);
struct elemento *crea_lista(int n_elem);
void stampa_lista(struct elemento *testa);

struct elemento *togli_neg(struct elemento *testa);
void ordina(struct elemento *testa);
struct elemento *sort_merging(struct elemento *l1, struct elemento *l2);
#endif //INC_13_02_2006_ESERCIZIO2_H
