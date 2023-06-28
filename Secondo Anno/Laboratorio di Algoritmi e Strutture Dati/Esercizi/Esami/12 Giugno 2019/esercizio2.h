#ifndef INC_12_GIUGNO_2019_ESERCIZIO2_H
#define INC_12_GIUGNO_2019_ESERCIZIO2_H

#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int inf;
    struct elemento *prev;
    struct elemento *next;
};

struct elemento *nuovo_nodo(int inf);
struct elemento *nuova_lista(int n_elem);
void stampa_lista(struct elemento *testa);
void ins_testa(struct elemento **testa, struct elemento *l);
void elimina_elemento(struct elemento **testa, struct elemento *del);
void sposta_pos_neg(struct elemento **testa_1, struct elemento **testa_2);

#endif //INC_12_GIUGNO_2019_ESERCIZIO2_H
