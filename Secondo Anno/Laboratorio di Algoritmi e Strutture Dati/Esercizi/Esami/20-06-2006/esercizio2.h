//
// Created by simli on 6/19/2023.
//

#ifndef INC_20_06_2006_ESERCIZIO2_H
#define INC_20_06_2006_ESERCIZIO2_H

#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int inf;
    struct elemento *prev;
    struct elemento *next;
};

struct elemento *new_node(int inf);
struct elemento *crea_lista(int n_elem);
void print_list(struct elemento *l);
int calcola_somma(struct elemento *l);
void togli_somma(struct elemento *l1, struct elemento *l2);

#endif //INC_20_06_2006_ESERCIZIO2_H


















