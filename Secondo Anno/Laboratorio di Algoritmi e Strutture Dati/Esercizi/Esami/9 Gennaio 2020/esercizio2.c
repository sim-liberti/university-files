#include "esercizio2.h"

struct elemento *nuovo_nodo(int inf, int p){
    struct elemento *n = (struct elemento *)malloc(sizeof(struct elemento));
    if (n != NULL){
        n->priority = p;
        n->inf = inf;
        n->prev = NULL;
        n->next = NULL;
    }
    return n;
}
struct elemento *nuova_lista(int n_elem, int p){
    struct elemento *temp;
    int val;

    printf("Testa: ");
    scanf("%d", &val);
    struct elemento *testa = nuovo_nodo(val, p);

    temp = testa;
    for (int i = 0; i < n_elem; i++){
        printf("Valore: ");
        scanf("%d", &val);
        temp->next = nuovo_nodo(val, p);
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
void elimina_elemento(struct elemento **testa, struct elemento *del){
    if (*testa == NULL || del == NULL) return;

    if (*testa == del)
        *testa = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if(del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}
struct elemento *calcola_minimo(struct elemento *l){
    struct elemento *min = l;
    struct elemento *temp = l;
    while (temp != NULL){
        if (temp->inf < min->inf) min = temp;
        temp = temp->next;
    }
    return min;
}
void togli_minimi(struct elemento *l1, struct elemento *l2, struct elemento *l3, struct elemento *l4){
    struct elemento *t1 = l1, *t2 = l2, *t3 = l3, *t4 = l4;
    struct elemento *min_1, *min_2, *min_3, *min_4;
    int priority = 1;
    while (t1 != NULL || t2 != NULL || t3 != NULL || t4 != NULL){
        min_1 = calcola_minimo(l1);
        min_2 = calcola_minimo(l2);
        min_3 = calcola_minimo(l3);
        min_4 = calcola_minimo(l4);

        if (min_1 != NULL) elimina_elemento(&(l1), min_1);
        if (min_2 != NULL) elimina_elemento(&(l2), min_2);
        if (min_3 != NULL) elimina_elemento(&(l3), min_3);
        if (min_4 != NULL) elimina_elemento(&(l4), min_4);

        t1 = t1->next;
        t2 = t2->next;
        t3 = t3->next;
        t4 = t4->next;

        if (priority == 4) priority = 1;
        else priority++;
    }
}











