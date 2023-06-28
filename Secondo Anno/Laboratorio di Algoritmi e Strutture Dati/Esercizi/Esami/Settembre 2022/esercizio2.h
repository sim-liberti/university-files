#ifndef SETTEMBRE_2022_ESERCIZIO2_H
#define SETTEMBRE_2022_ESERCIZIO2_H

#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int key;
    struct nodo *left;
    struct nodo *right;
};

int vuoto(struct nodo *root);
void visita_preordine(struct nodo *root);
void inserisci_nodo(struct nodo **root, int key);
int controllo_abr(struct nodo *root);
int cerca_minimo(struct nodo *root);
int cerca_massimo(struct nodo *root);
void controlla_abr_stampa_minimo(struct nodo *root);
#endif //SETTEMBRE_2022_ESERCIZIO2_H
