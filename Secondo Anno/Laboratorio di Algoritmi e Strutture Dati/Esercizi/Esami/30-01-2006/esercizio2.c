//
// Created by simli on 6/17/2023.
//

#include "esercizio2.h"

struct elemento *crea_nodo(int inf){
    struct elemento *new = (struct elemento *)malloc(sizeof(struct elemento));
    if (new != NULL){
        new->inf = inf;
        new->prev = NULL;
        new->next = NULL;
    }
    return new;
}
struct elemento *crea_lista(int n_elem){
    struct elemento *testa, *temp;
    int val;
    do {
        printf("Elemento di testa: ");
        scanf("%d", &val);
        if (val <= 0) printf("Solo numeri interi. \n");
    } while(val <= 0);
    testa = crea_nodo(val);
    temp = testa;
    for (int i = 1; i < n_elem; i++){
        do {
            printf("Elemento %d: ", i);
            scanf("%d", &val);
            if (val <= 0) printf("Solo numeri interi. \n");
        } while(val <= 0);
        temp->next = crea_nodo(val);
        temp->next->prev = temp;
        temp = temp->next;
    }
    temp->next = NULL;
    return testa;
}
void stampa_lista(struct elemento *lista){
    struct elemento *temp = lista;
    while (temp != NULL){
        if (temp->next == NULL)
            printf("%d -> NULL", temp->inf);
        else printf("%d -> ", temp->inf);
        temp = temp->next;
    }
}
void togli_dispari_pari(struct elemento **l, int a){
    struct elemento *head = NULL;
    if (*l != NULL) {
        head = *l;
        switch (a) {
            case 0:
                /* Togli numeri pari */
                while (*l != NULL) {
                    if ((*l)->inf % 2 == 0) {
                        if ((*l)->prev == NULL) {
                            *l = (*l)->next;
                            (*l)->prev = NULL;
                            head = *l;
                        } else if ((*l)->next == NULL) {
                            (*l)->prev->next = NULL;
                            *l = NULL;
                        } else {
                            (*l)->next->prev = (*l)->prev;
                            (*l)->prev->next = (*l)->next;
                            *l = (*l)->next;
                        }
                    } else *l = (*l)->next;
                }
            case 1:
                /* Togli numeri dispari */
                while (*l != NULL) {
                    if ((*l)->inf % 2 != 0) {
                        if ((*l)->prev == NULL) {
                            *l = (*l)->next;
                            (*l)->prev = NULL;
                            head = *l;
                        } else if ((*l)->next == NULL) {
                            (*l)->prev->next = NULL;
                            l = NULL;
                        } else {
                            (*l)->next->prev = (*l)->prev;
                            (*l)->prev->next = (*l)->next;
                            *l = (*l)->next;
                        }
                    } else *l = (*l)->next;
                }
            default:
                break;
        }
    }
    *l = head;
}
struct elemento *interleaving(struct elemento *l1, struct elemento *l2){
    static struct elemento *temp = NULL;
    if (l1 == NULL && l2 == NULL) return temp;
    if (l1 == NULL && l2 != NULL){
        temp = l2;

    } else if (l1 != NULL && l2 == NULL){

    }
}
