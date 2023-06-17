#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int key;
    char name[255];
    struct node *next;
}node;
typedef struct AdjList{
    struct node *head;
}AdjList;
typedef struct graph{
    int nv;
    struct AdjList *array;
}graph;

graph *g_empty(int nv){
    graph *g = (graph *)malloc(sizeof(graph));
    g->nv = nv;
    g->array = (AdjList *)malloc(nv * sizeof(AdjList));
    for (int i = 0; i < nv; i++)
        g->array[i].head = NULL;
    return g;
}
node *new_node(int data, char name[255]){
    node *n = (node *)malloc(sizeof(node));
    n->key = data;
    strcpy(n->name, name);
    n->next = NULL;
    return n;
}
void new_edge(graph *g, int src, int dest, char n_src[255], char n_dest[255]){
    node *check = NULL;
    /* Edge from src to dest */
    node *newNode = new_node(dest, n_dest);
    if (g->array[src].head == NULL){
        newNode->next = g->array[src].head;
        g->array[src].head = newNode;
    }
    else{
        check = g->array[src].head;
        while(check->next != NULL)
            check = check->next;
        check->next = newNode;
    }
    /* Edge from dest to src */
    newNode = new_node(src, n_src);
    if (g->array[dest].head == NULL){
        newNode->next = g->array[dest].head;
        g->array[dest].head = newNode;
    }
    else{
        check = g->array[dest].head;
        while(check->next != NULL)
            check = check->next;
        check->next = newNode;
    }
}
void g_print(graph *g){
    for (int i = 0; i < g->nv; i++){
        node *temp = g->array[i].head;
        printf("\nLista di adiacenza di %d -> ", i);
        while (temp){
            printf("%d (%s) | ", temp->key, temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    graph *g = g_empty(5);

    new_edge(g, 0, 1, "Napoli", "Milano");
    new_edge(g, 0, 4, "Napoli", "Firenze");
    new_edge(g, 1, 2, "Milano", "Bari");
    new_edge(g, 1, 3, "Milano", "Roma");
    new_edge(g, 1, 4, "Milano", "Firenze");
    new_edge(g, 2, 3, "Bari", "Roma");
    new_edge(g, 3, 4, "Roma", "Firenze");

    g_print(g);

    return 0;
}
