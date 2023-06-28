#include "esercizio2.h"

int main() {
    struct elemento *l1 = nuova_lista(5);
    printf("\n");
    struct elemento *l2 = nuova_lista(5);
    printf("\nLista 1:\n");
    stampa_lista(l1);
    printf("\nLista 2:\n");
    stampa_lista(l2);

    printf("\n\n\n");
    struct elemento *temp = l1;

    sposta_pos_neg(&(l1), &(l2));
    stampa_lista(l1);

    return 0;
}
