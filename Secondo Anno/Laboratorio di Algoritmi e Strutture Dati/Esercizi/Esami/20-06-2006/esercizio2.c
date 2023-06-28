//
// Created by simli on 6/19/2023.
//

#include "esercizio2.h"
struct elemento *new_node(int inf){
    struct elemento *n = (struct elemento *)malloc(sizeof(struct elemento));
    if (n != NULL){
        n->inf = inf;
        n->prev = NULL;
        n->next = NULL;
    }
    return n;
}
struct elemento *crea_lista(int n_elem){
    struct elemento *testa, *temp;
    int val;

    printf("Testa: ");
    scanf("%d", &val);
    testa = new_node(val);

    temp = testa;

    for (int i = 1; i < n_elem; i++){
        printf("Elemento %d: ", i);
        scanf("%d", &val);
        temp->next = new_node(val);
        temp->next->prev = temp;
        temp = temp->next;
    }
    temp->next = NULL;

    return testa;
}
void print_list(struct elemento *l){
    while(l != NULL){
        printf("%d <-> ", l->inf);
        l = l->next;
    }
    printf("NULL");
}
int calcola_somma(struct elemento *l){
    int sum = 0;
    while(l != NULL){
        sum += l->inf;
        l = l->next;
    }
    return sum;
}

struct elemento *delete_node(struct elemento *l){
    if (l->prev == NULL){
        l = l->next;
        l->next->prev = NULL;
    }
    else if(l->next == NULL){
        l->prev->next = NULL;
        l = NULL;
    }
    else{
        l->next->prev = l->prev;
        l->prev->next = l->next;
        l = l->next;
    }
    return l;
}

void togli_somma(struct elemento *l1, struct elemento *l2){
    struct elemento *testa1 = l1;
    struct elemento *testa2 = l2;
    int terminato = 0;
    int counter = 1;
    int inverti = 0;
    int somma;
    int trovato = 0;

    while (terminato == 0){
        l1 = testa1;
        l2 = testa2;
        printf("\n\nIterazione %d: ", counter);
        if (inverti == 0){
            somma = calcola_somma(l1);
            printf("\nSomma elementi lista 1: %d", somma);
            while(l2 != NULL){
                if (l2->inf == somma) {
                    l2 = delete_node(l2);
                    if (l2->prev == NULL) testa2 = l2;
                    trovato = 1;
                }
                if (l2 != NULL) l2 = l2->next;
            }
            if (trovato != 1) terminato = 1;
            inverti = 1;
            printf("\nLista attuale 1: ");
            print_list(l1);
        }
        else{
            somma = calcola_somma(l2);
            printf("\nSomma elementi lista 2: %d", somma);
            while(l1 != NULL){
                if (l1->inf == somma) {
                    l1 = delete_node(l1);
                    if (l2->prev == NULL) testa1 = l1;
                    trovato = 1;
                }
                if (trovato == 1) l1 = l1->next;
                else terminato = 1;
            }
            inverti = 0;
            printf("\nLista attuale 1: ");
            print_list(l1);
        }
    }
}





