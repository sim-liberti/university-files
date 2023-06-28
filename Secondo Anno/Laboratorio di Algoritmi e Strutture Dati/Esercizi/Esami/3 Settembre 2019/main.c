#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int key;
    int peso;
    struct nodo *next;
};
struct grafo{
    int nv;
    struct nodo **adj;
};

struct grafo *g_empty(int nv){
    struct grafo *g = (struct grafo *)malloc(sizeof(struct grafo));
    if (g == NULL) printf("\nErrore di allocazione nel grafo\n");
    else{
        g->adj = (struct nodo **)malloc(nv * sizeof(struct nodo *));
        if (g->adj != NULL){
            g->nv = nv;
            for (int i = 0; i < nv; i++) g->adj[i] = NULL;
        } else{
            printf("\nErrore di allocazione della lista\n");
            free(g);
            g = NULL;
        }
    }
    return g;
}
void g_add(struct grafo *g, int src, int dest, int peso){
    struct nodo *new, *e;
    new = (struct nodo *)malloc(sizeof(struct nodo));

    if (g != NULL){
        if (new == NULL) {
            printf("\nErrore di allocazione del nodo\n");
            return;
        }
        if (src < 0 || dest < 0 || src >= g->nv || dest >= g->nv){
            printf("\nVertici non corretti");
            return;
        }
        new->key = dest;
        new->peso = peso;
        new->next = NULL;
        if (g->adj[src] == NULL) g->adj[src] = new;
        else{
            e = g->adj[src];
            if(e->key == dest){
                printf("Errore, l'arco (%d , %d) esiste già!\n", src, dest);
                return;
            }
            while(e->next != NULL){
                e = e->next;
            }
            e->next = new;
        }
    }
}

int is_empty(struct grafo *G){
    return (G == NULL);
}

void g_print(struct grafo *G){
    int i, ne = 0;
    struct nodo *e;
    if(!is_empty(G)){
        printf("\nIl grafo ha %d vertici\n", G->nv);
        for(i = 0; i < G->nv; i++){
            printf("nodi adiacenti al nodo %d -> ", i);
            e = G->adj[i];
            while(e != NULL){
                printf("%d (peso = %d) | ", e->key, e->peso);
                ne = ne+1;
                e = e->next;
            }
            printf("\n");
        }
        printf("Il grafo ha %d archi \n", ne);
    }
}
int grado_uscente(struct grafo *g, int nodo){
    if (is_empty(g) || nodo >= g->nv) return 0;
    int grado = 0;
    struct nodo *n = g->adj[nodo];
    while (n != NULL){
        grado++;
        n = n->next;
    }
    return grado;
}
int grado_entrante(struct grafo *g, int nodo){
    if (is_empty(g) || nodo >= g->nv) return 0;
    int grado = 0;
    for (int i = 0; i < g->nv; i++){
        struct nodo *n = g->adj[i];
        while (n != NULL) {
            if (n->key == nodo)
                grado++;
            n = n->next;
        }
    }
    return grado;
}
int peso_totale_uscente(struct grafo *g, int nodo){
    if (is_empty(g) || nodo >= g->nv) return 0;
    int peso = 0;

    struct nodo *n = g->adj[nodo];
    while (n != NULL){
        peso += n->peso;
        n = n->next;
    }

    return peso;
}

struct grafo *trasposto(struct grafo *g){
    if (is_empty(g)) return NULL;

    struct grafo *trasposto = g_empty(g->nv);

    for (int i = 0; i < g->nv; i++){
        struct nodo *temp = g->adj[i];
        while (temp != NULL){
            g_add(trasposto, temp->key, i, temp->peso);
            temp = temp->next;
        }
    }
    return trasposto;
}
void cancella_arco(struct grafo *g, int src, int dest) {
    struct nodo *prev = NULL;
    struct nodo *curr = g->adj[src];

    while(curr != NULL) {
        if(curr->key == dest) {
            if(prev == NULL) g->adj[src] = curr->next;
            else prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
void cancella_nodo(struct grafo *g, int src) {
    int i;
    for(i = 0; i < g->nv; i++)
        cancella_arco(g, i, src);

    struct nodo *curr = g->adj[src];
    while(curr != NULL) {
        struct nodo *tmp = curr->next;
        free(curr);
        curr = tmp;
    }

    for(i = 0; i < g->nv; i++) {
        curr = g->adj[i];
        while(curr != NULL) {
            if(curr->key > src) curr->key--;
            curr = curr->next;
        }
    }

    for(i = src + 1; i < g->nv; i++)
        g->adj[i - 1] = g->adj[i];
    struct nodo **e = NULL;

    e = (struct nodo *)realloc(g->adj, (g->nv-1)*sizeof(struct nodo));
    if(e == NULL) exit(-1);

    g->adj = e;
    g->nv--;
}

int main(){
    struct grafo *G = g_empty(6);

    struct nodo *E;

    g_add(G, 0, 1, 2);
    g_add(G, 0, 2, 6);
    g_add(G, 2, 3, 5);
    g_add(G, 1, 3, 7);
    g_add(G, 3, 5, 9);
    g_add(G, 4, 2, 9);
    g_add(G, 5, 1, 5);

    printf("\nGrafo orientato: \n");
    g_print(G);

    cancella_nodo(G, 0);
    printf("\nGrafo modificato: \n");
    g_print(G);

    return 0;
}
