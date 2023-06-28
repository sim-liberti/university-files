#include "esercizio3.h"

int main() {
    grafo *g = nuovo_grafo(3);
    aggiungi_arco(g, 0, 1, 3);
    aggiungi_arco(g, 1, 2, 6);
    aggiungi_arco(g, 2, 0, 10);
    aggiungi_arco(g, 2, 1, 3);
    aggiungi_arco(g, 1, 0, 6);

    stampa_grafo(g);

    return 0;
}
