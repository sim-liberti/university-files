#include <stdio.h>

//#include "esercizio1.h"
#include "esercizio2.h"

int main() {
    struct elemento *Lista_1,*Lista_2;

    printf("Creazione Lista 1:\n");
    Lista_1 = crea_lista(4);
    printf("\nCreazione Lista 2:\n");
    Lista_2 = crea_lista(3);

    printf("\nLista 1:\n");
    stampa_lista(Lista_1);
    printf("\nLista 2:\n");
    stampa_lista(Lista_2);


    togli_dispari_pari(Lista_2, 0);
    printf("\n\nLista 2 modificata:\n");
    stampa_lista(Lista_2);

    togli_dispari_pari(Lista_1, 1);
    printf("\n\nLista 1 modificata:\n");
    stampa_lista(Lista_1);



    return 0;
}
