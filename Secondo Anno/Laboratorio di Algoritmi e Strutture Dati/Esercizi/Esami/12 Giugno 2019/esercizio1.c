#include "esercizio1.h"

int is_empty(int Q[]){
    return Q[0] == 0;
}
int is_full(int Q[]){
    return Q[0] == MAX;
}
void enqueue(int *Q, int val){
    if (Q[0] == 0) Q[0] = 1;
    Q[Q[MAX+1]] = val;
    Q[MAX+1] = (Q[MAX+1] % MAX) + 1;
}
int dequeue(int Q[]){
    int val = Q[Q[0]];
    Q[0] = (Q[0] % MAX) + 1;
    if (Q[0] == Q[MAX+1]){
        Q[0] = 0;
        Q[MAX+1] = 1;
    }
    return val;
}
void print_queue(int Q[]){
    int val = 1;
    if (is_empty(Q)) return;

    else
    {
        val = dequeue(Q);
        printf("%d | ", val);
        print_queue(Q);
        enqueue(Q, val);
    }
}

void reverse(int Q[]){
    int val = 1;
    if (is_empty(Q)) return;
    else
    {
        val = dequeue(Q);
        reverse(Q);
        enqueue(Q, val);
    }
}

void togli_pos_neg(int Q[], int scelta){
    int val = 0;

    if (is_empty(Q))
        return;
    else
    {
        val = dequeue(Q);
        togli_pos_neg(Q, scelta);
        if (((scelta == 0) && (val < 0)) || ((scelta == 1) && (val >= 0)))
            enqueue(Q, val);
    }
}