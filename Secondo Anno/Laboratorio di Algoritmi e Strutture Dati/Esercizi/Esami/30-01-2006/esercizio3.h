//
// Created by simli on 6/18/2023.
//

#ifndef INC_30_01_2006_ESERCIZIO3_H
#define INC_30_01_2006_ESERCIZIO3_H

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int inforadice;
    struct nodo *left;
    struct nodo *right;
};

int empty(struct nodo *root);
void tree_insert(struct nodo **root, int val);
void preorder_visit(struct nodo *root);

#endif //INC_30_01_2006_ESERCIZIO3_H
