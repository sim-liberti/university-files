#ifndef INC_12_GIUGNO_2019_ESERCIZIO1_H
#define INC_12_GIUGNO_2019_ESERCIZIO1_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int is_empty(int Q[]);
int is_full(int Q[]);
void enqueue(int *Q, int val);
int dequeue(int Q[]);
void print_queue(int Q[]);
void reverse(int Q[]);
void togli_pos_neg(int Q[], int scelta);

#endif //INC_12_GIUGNO_2019_ESERCIZIO1_H
