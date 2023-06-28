#include "esercizio2.h"

int main() {
    printf("- Lista 1 -\n");
    struct elemento *l1 = nuova_lista(6, 1);
    printf("\n- Lista 2 -\n");
    struct elemento *l2 = nuova_lista(4, 2);
    printf("\n- Lista 3 -\n");
    struct elemento *l3 = nuova_lista(5, 3);
    printf("\n- Lista 4 -\n");
    struct elemento *l4 = nuova_lista(7, 4);

    printf("\n------ Liste inserite ------");
    printf("\nLista 1 (priorita': %d): ", l1->priority);
    stampa_lista(l1);
    printf("\nLista 2 (priorita': %d): ", l2->priority);
    stampa_lista(l2);
    printf("\nLista 3 (priorita': %d): ", l3->priority);
    stampa_lista(l3);
    printf("\nLista 4 (priorita': %d): ", l4->priority);
    stampa_lista(l4);

    togli_minimi(l1, l2, l3, l4);
    printf("\n\n------ Liste modificate ------");
    printf("\nLista 1 (priorita': %d): ", l1->priority);
    stampa_lista(l1);
    printf("\nLista 2 (priorita': %d): ", l2->priority);
    stampa_lista(l2);
    printf("\nLista 3 (priorita': %d): ", l3->priority);
    stampa_lista(l3);
    printf("\nLista 4 (priorita': %d): ", l4->priority);
    stampa_lista(l4);

    return 0;
}
