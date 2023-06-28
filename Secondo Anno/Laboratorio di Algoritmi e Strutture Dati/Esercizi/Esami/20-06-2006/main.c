#include "esercizio2.h"

#include <time.h>
#include <stdlib.h>

int main() {
    struct elemento *l1, *l2;

    printf("Creazione lista 1: \n");
    l1 = crea_lista(6);
    printf("\nCreazione lista 2: \n");
    l2 = crea_lista(4);
    printf("\n\nLista 1: ");
    print_list(l1);
    printf("\nLista 2: ");
    print_list(l2);

    printf("\n\nModifico le liste:\n\n");
    togli_somma(l1, l2);

    return 0;
}
