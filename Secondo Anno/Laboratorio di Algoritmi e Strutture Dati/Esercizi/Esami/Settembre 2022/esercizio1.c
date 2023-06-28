#include "esercizio1.h"

struct list *nuovo_nodo(int index, int data){
    struct list *new  = (struct list *)malloc(sizeof(struct list));
    if (new != NULL){
        new->index = index;
        new->data = data;
        new->prev = NULL;
        new->next = NULL;
    }
    return new;
}
struct list *nuova_lista(int n_elem){
    struct list *temp;
    int data;

    if (n_elem == 0) return NULL;

    printf("Testa: ");
    scanf("%d", &data);

    struct list *head = nuovo_nodo(1, data);
    if (n_elem == 1){
        head->next = head;
        head->prev = head;
    }
    else{
        head->next = NULL;
        head->prev = NULL;
        temp = head;
        for (int i = 2; i <= n_elem; i++){
            printf("Valore: ");
            scanf("%d", &data);
            temp->next = nuovo_nodo(i, data);
            temp->next->prev = temp;
            temp = temp->next;
        }
        temp->next = head;
        head->prev = temp;
    }

    return head;
}
void stampa_lista(struct list *l_head){
    struct list *inizio = l_head, *temp = l_head;

    if (l_head != NULL){
        do{
            printf("[%d]-%d -> ", temp->index, temp->data);
            temp = temp->next;
        }while(temp != inizio);
        printf("(testa)[%d]-%d -> ...", temp->index, temp->data);
    }
}
struct list *sostituisci_media(struct list *l_head){
    struct list *inizio = l_head;
    struct list *temp = l_head;
    int media;
    do{
        media = calcola_media(temp);
        printf("\nSosituisco %d con la media trovata: %d", temp->data, media);
        temp->data = media;
        temp = temp->next;
    } while(temp != inizio);

    return l_head;
}
int calcola_media(struct list *l_current){
    struct list *temp_sx = l_current;
    struct list *temp_dx = l_current;
    int sum = 0;
    int n_elem = 0;

    do{
        sum += temp_sx->data;
        n_elem++;
        temp_sx = temp_sx->prev;
    }while(temp_sx->index != 1);
    do{
        sum += temp_dx->data;
        n_elem++;
        temp_dx = temp_dx->prev;
    }while(temp_dx->index != 1);

    return sum/n_elem;
}
