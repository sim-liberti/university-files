//
// Created by simli on 6/19/2023.
//

#include "esercizio1.h"
void push(int *s, int val){
    s[0] = s[0] + 1;
    s[s[0]] = val;
}
int pop(int *s){
    s[0] = s[0] - 1;
    return s[s[0]+1];
}
int s_empty(int *s){
    return s[0] == 0;
}
int s_full(int *s){
    return s[0] == MAX;
}
void s_print(int *s){
    int val;
    if (s_empty(s)) return;

    val = pop(s);
    printf("%d | ", val);
    s_print(s);
    push(s, val);
}
void moltiplica_stack(int *s1, int *s2){
    int val1, val2;

    if (s_empty(s1)) return;

    val1 = pop(s1);
    val2 = pop(s2);
    moltiplica_stack(s1, s2);
    push(s1, val1*val2);
    push(s2, val2);
}

void insert_at_bottom(int *s, int val){
    if (s_empty(s)) push(s, val);
    else{
        int x = pop(s);
        insert_at_bottom(s, val);
        push(s, x);
    }
}
void reverse(int *s){
    if (!s_empty(s)){
        int val = pop(s);
        reverse(s);
        insert_at_bottom(s, val);
    }
}







