//
// Created by simli on 6/19/2023.
//

#include "esercizio3.h"

int is_empty(grafo *g){
    return g->nv == 0;
}
grafo *nuovo_grafo(int nv){
    grafo *ng = (grafo *)malloc(sizeof(grafo));
    ng->nv = nv;
    ng->adj = (nodo **)malloc(nv * sizeof(nodo *));

    for (int i = 0; i < ng->nv; i++) ng->adj[i] = NULL;

    return ng;
}
nodo *nuovo_nodo(int k, int p){
    nodo *n = (nodo *)malloc(sizeof(nodo));
    if (n != NULL){
        n->key = k;
        n->peso = p;
        n->next = NULL;
    }
    return n;
}
nodo *trova_nodo(grafo *g, int src, int dest){
    if (is_empty(g)) return NULL;
    nodo *n = g->adj[src];
    while (n != NULL){
        if (n->key == dest) return n;
        n = n->next;
    }
    return NULL;
}
grafo *aggiungi_nodo(grafo *g){
    g->nv++;
    g->adj = realloc(g->adj, g->nv * sizeof(nodo *));
    if (g->adj != NULL) g->adj[g->nv-1] = NULL;
    return g;
}
grafo *aggiungi_arco(grafo *g, int src, int dest, int p){
    if (!is_empty(g)){

        if (src >= 0 && dest >= 0) {

            if (src < g->nv && dest < g->nv && p > 0) {

                nodo *n = nuovo_nodo(dest, p);

                if (n != NULL) {
                    nodo *e = trova_nodo(g, src, dest);
                    if (e != NULL) e->peso += p;
                    else {
                        n->next = g->adj[src];
                        g->adj[src] = n;
                    }
                }

            }
            else printf("I nodi non esistono nel grafo o il peso e' <= 0\n\n");
        }
        else printf("I due nodi non sono presenti nel grafo. \n\n");
    }
    return g;
}
void stampa_grafo(grafo *g){
    if (is_empty(g)) printf("Grafo vuoto. \n\n");
    else{
        for (int i = 0; i < g->nv; i++){
            printf("[%d] -> ", i);
            nodo *n = g->adj[i];
            while(n != NULL){
                printf("%d|%d - ", n->key, n->peso);
                n = n->next;
            }
            printf("NULL\n");
        }
    }
}
void cancella_arco(grafo *g, int src, int dest){
    if (is_empty(g)) return;
    nodo *n = g->adj[src];
    nodo *prev = NULL;

    while (n != NULL){
        if (n->key == dest){
            prev->next = n->next;
            free(n);
            n = prev->next;
        }
        else{
            prev = n;
            n = n->next;
        }
    }
}
void free_adj(nodo *adj){
    if (adj == NULL) return;
    free(adj->next);
    free(adj);
}
void cancella_nodo(grafo *g, int src){
    if (!is_empty(g)) return;
    free_adj(g->adj[src]);

    for (int i = 0; i < g->nv; i++){
        nodo *n = g->adj[i];
        nodo *prev = NULL;
        while (n != NULL){
            if (n->key == src){
                if (prev == NULL){
                    nodo *temp = n->next;
                    g->adj[i] = n->next;
                    free(n);
                    n = temp;
                } else{
                    prev->next = n->next;
                    free(n);
                    n = prev->next;
                }
            } else{
                prev = n;
                n = n->next;
            }
        }
    }
}















