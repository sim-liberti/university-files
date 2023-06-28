//
// Created by simli on 6/19/2023.
//

#ifndef SETTEMBRE_2022_ESERCIZIO3_H
#define SETTEMBRE_2022_ESERCIZIO3_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int key;
    int peso;
    struct nodo *next;
}nodo;
typedef struct grafo{
    int nv;
    struct nodo **adj;
}grafo;

int is_empty(grafo *g);
nodo *adiacenti(grafo *g, int index);
nodo **incidenti(grafo * g, int index);
grafo *nuovo_grafo(int nv);
nodo *nuovo_nodo(int k, int p);
grafo *aggiungi_nodo(grafo *g);
nodo *trova_nodo(grafo *g, int src, int dest);
void stampa_grafo(grafo *g);
grafo *aggiungi_arco(grafo *g, int src, int dest, int p);
void cancella_nodo(grafo *g, int src);
void cancella_arco(grafo *g, int index, int dest);
void free_adj(nodo *adj);
void free_arco(grafo *g);
grafo *calcola_trasposto(grafo *g);

#endif //SETTEMBRE_2022_ESERCIZIO3_H
