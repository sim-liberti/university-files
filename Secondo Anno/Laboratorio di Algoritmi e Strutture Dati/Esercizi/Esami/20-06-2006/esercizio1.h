//
// Created by simli on 6/19/2023.
//

#ifndef INC_20_06_2006_ESERCIZIO1_H
#define INC_20_06_2006_ESERCIZIO1_H

#include <stdio.h>

#define MAX 6

void push(int *s, int val);
int pop(int *s);
int s_empty(int *s);
int s_full(int *s);
void s_print(int *s);
void moltiplica_stack(int *s1, int *s2);

void reverse(int *s);
void insert_at_bottom(int *s, int val);

#endif //INC_20_06_2006_ESERCIZIO1_H
