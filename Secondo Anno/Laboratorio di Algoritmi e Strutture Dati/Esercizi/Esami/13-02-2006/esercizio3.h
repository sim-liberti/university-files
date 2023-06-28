//
// Created by simli on 6/18/2023.
//

#ifndef INC_13_02_2006_ESERCIZIO3_H
#define INC_13_02_2006_ESERCIZIO3_H

#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
    int key;
    int peso;
    struct edge *next;
}edge;

typedef struct graph {
    int nv;
    edge **adj;
}graph;

graph *g_empty(int n);
int is_empty(graph *g);
void g_print(graph *g);
void g_add(graph *g, int u, int v, int peso);

#endif //INC_13_02_2006_ESERCIZIO3_H
