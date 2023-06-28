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
struct elemento *nuova_lista(int n_elem){
    struct elemento *temp;
    int val;

    printf("Testa: ");
    scanf("%d", &val);
    struct elemento *testa = nuovo_nodo(val);

    temp = testa;
    for (int i = 0; i < n_elem; i++){
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
    printf("NULL <- ");
    while (temp != NULL){
        if (temp->next != NULL) printf("[%d] <-> ", temp->inf);
        else printf("[%d] -> ", temp->inf);
        temp = temp->next;
    }
    printf("NULL");
}
void ins_testa(struct elemento **testa, struct elemento *l){
    (*testa)->prev = l;
    l->next = *testa;
    l->prev = NULL;
    *testa = l;
}
void elimina_elemento(struct elemento **testa, struct elemento *del){
    /* Caso base */
    if (*testa == NULL || del == NULL)
        return;

    /* Cancello in testa */
    if (*testa == del)
        *testa = del->next;

    /* Modifico se non è l'ultimo nodo */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Modifico se non è l'primo nodo */
    if (del->prev != NULL)
        del->prev->next = del->next;

    /* Libero la memoria */
    free(del);
    return;
}
void sposta_pos_neg(struct elemento **testa_1, struct elemento **testa_2){
    struct elemento *temp_1 = *testa_1;
    struct elemento *temp_2 = *testa_2;

    if (temp_1 == NULL && temp_2 == NULL) return;

    if (temp_1 == NULL && temp_2 != NULL){
        if (temp_2->inf > 0){
            ins_testa(testa_1, temp_2);
            elimina_elemento(testa_2, temp_2);
            sposta_pos_neg(testa_1, &(*testa_2)->next);
        }
    } else if (temp_1 != NULL && temp_2 == NULL){
        if (temp_1->inf > 0){
            ins_testa(testa_2, temp_1);
            elimina_elemento(testa_1, temp_1);
            sposta_pos_neg(&(*testa_1)->next, testa_2);
        }
    } else{
        if (temp_1->inf > 0){
            ins_testa(testa_2, temp_1);
            elimina_elemento(testa_1, temp_1);
            *testa_1 = (*testa_1)->next;
        }
        if (temp_2->inf > 0){
            ins_testa(testa_1, temp_2);
            elimina_elemento(testa_2, temp_2);
            *testa_2 = (*testa_2)->next;
        }
        sposta_pos_neg(testa_1, testa_2);
    }
}








