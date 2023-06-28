//
// Created by simli on 6/17/2023.
//

#ifndef INC_30_01_2006_ESERCIZIO2_H
#define INC_30_01_2006_ESERCIZIO2_H

#include <stdio.h>
#include <stdlib.h>

struct elemento {
    struct elemento *prev;
    int inf;
    struct elemento *next;
};

struct elemento *crea_nodo(int inf);
struct elemento *crea_lista(int n_elem);
void stampa_lista(struct elemento *lista);
void togli_dispari_pari(struct elemento **l, int a);
struct elemento *interleaving(struct elemento *l1, struct elemento *l2);

#endif //INC_30_01_2006_ESERCIZIO2_H
