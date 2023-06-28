//
// Created by simli on 6/18/2023.
//

#include "esercizio2.h"

struct elemento *nuovo_nodo(int inf){
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
    testa = nuovo_nodo(val);
    temp = testa;

    for (int i = 1; i < n_elem; i++){
        printf("Valore: ");
        scanf("%d", &val);
        temp->next = nuovo_nodo(val);
        temp->next->prev = temp;
        temp = temp->next;
    }
    temp->next = NULL;
    return testa;
}
void stampa_lista(struct elemento *testa){
    struct elemento *temp = testa;
    while (temp != NULL){
        if (temp->next == NULL) printf("%d -> NULL", temp->inf);
        else printf("%d -> ", temp->inf);
        temp = temp->next;
    }
}
struct elemento *togli_neg(struct elemento *testa){
    if(testa == NULL){
        return NULL;
    } else {
        struct elemento *rest = togli_neg(testa->next);
        if(testa->inf < 0){
            if(rest != NULL){
                rest->prev = NULL;
            }
            free(testa);
            return rest;
        } else {
            if(rest != NULL){
                rest->prev = testa;
            }
            testa->next = rest;
            return testa;
        }
    }
}
void ordina(struct elemento *testa){
    struct elemento *current = NULL;
    struct elemento *index = NULL;
    int temp;

    testa = togli_neg(testa);

    if (testa != NULL){
        for (current = testa; current->next != NULL; current = current->next)
            for (index = current->next; index != NULL; index = index->next)
                if (current->inf > index->inf){
                    temp = current->inf;
                    current->inf = index->inf;
                    index->inf = temp;
                }
    }
}

struct elemento *sort_merging(struct elemento *l1, struct elemento *l2){
    struct elemento *l3, *temp;

    if (l1->inf < l2->inf){
        l3 = nuovo_nodo(l1->inf);
        l1 = l1->next;
    }else{
        l3 = nuovo_nodo(l2->inf);
        l2 = l2->next;
    }

    temp = l3;
    while (l1 != NULL || l2 != NULL){
        if (l1 != NULL && l2 == NULL){
            temp->next = nuovo_nodo(l1->inf);
            temp->next->prev = temp;
            temp = temp->next;
            l1 = l1->next;
        } else if (l1 == NULL && l2 != NULL){
            temp->next = nuovo_nodo(l2->inf);
            temp->next->prev = temp;
            temp = temp->next;
            l2 = l2->next;
        } else{
            if (l1->inf < l2->inf){
                temp->next = nuovo_nodo(l1->inf);
                temp->next->prev = temp;
                temp = temp->next;
                l1 = l1->next;
            } else{
                temp->next = nuovo_nodo(l2->inf);
                temp->next->prev = temp;
                temp = temp->next;
                l2 = l2->next;
            }
        }
    }

    return l3;
}
