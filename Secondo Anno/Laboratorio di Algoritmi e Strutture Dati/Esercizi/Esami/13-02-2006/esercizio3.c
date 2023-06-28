//
// Created by simli on 6/18/2023.
//

#include "esercizio3.h"

int is_empty(graph *g){
    return g == NULL;
}
graph *g_empty(int n_vertici){
    graph *g;

    g = (graph *)malloc(sizeof(graph));
    if (g == NULL) printf("Errore di allocazione del grafo.\n");
    else{
        g->adj = (edge **)malloc(n_vertici * sizeof(edge *));
        if (g->adj == NULL) {
            printf("Errore di allocazione della lista di adiacenza.\n");
            free(g);
            g = NULL;
        }
        else{
            g->nv = n_vertici;
            for (int i = 0; i < n_vertici; i++) g->adj[i] = NULL;
        }
    }
    return g;
}
void g_print(graph *g){
    int n_archi = 0;
    edge *e;

    if (!is_empty(g)){
        printf("\nIlgrafo ha %d vertici.\n", g->nv);
        for (int i = 0; i < g->nv; i++){
            printf("Nodi adiacenti a %d -> ", i);
            e = g->adj[i];
            while(e != NULL) {
                printf("%d (peso: %d) | ", e->key, e->peso);
                e = e->next;
                n_archi += 1;
            }
            printf("\n");
        }
        printf("\nIl grafo ha %d archi.\n", n_archi);
    }
}
void g_add(graph *g, int u, int v, int peso){
    edge *new, *e;
    new = (edge *)malloc(sizeof(edge));
    if (g != NULL){
       if (new == NULL) printf("Errore di allocazione del nuovo arco.\n");
       else{
           if(u < 0 || v < 0 || u >= g->nv || v >= g->nv) printf("ERRORE: vertici non corretti\n");
           else{
               new->key = v;
               new->next = NULL;
               if (g->adj[u] == NULL) g->adj[u] = new;
               else{
                   e = g->adj[u];
                   if(e->key == v){
                       printf("Errore, l'arco (%d , %d) esiste già.\n", u, v);
                       return;
                   }
                   while (e->next != NULL) e = e->next;
                   e->next = new;
               }
           }
       }
    }
}













