//
// Created by simli on 6/18/2023.
//

#ifndef INC_13_02_2006_ESERCIZIO1_H
#define INC_13_02_2006_ESERCIZIO1_H

#include <stdio.h>

#define MAX 5

int empty_queue(int Q[]);
int full_queue(int Q[]);
void enqueue(int Q[], int val);
int dequeue(int Q[]);
void reverse(int Q[]);
void stampa_queue(int Q[]);
void new_queue(int Q[]);

#endif //INC_13_02_2006_ESERCIZIO1_H
