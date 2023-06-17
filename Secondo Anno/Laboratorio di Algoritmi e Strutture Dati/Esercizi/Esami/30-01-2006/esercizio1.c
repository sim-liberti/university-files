/*Si consideri uno Stack S, implementato con array S[MAX]. Si implementi la funzione
ricorsiva void raddoppia Stack(int S[MAX]) che raddoppia le occorrenze di ogni
elemento nello stack lasciando invariato l’ordine degli elementi. Si ricorda che lo stack è
una struttura dati che permette l’accesso ai suoi dati solo dal top.
Esempio: stack iniziale 1|3|3|6|2 -- stack finale 1|1|3|3|3|3|6|6|2|2*/

#include "esercizio1.h"

void push(int *S, int val){
    S[0] = S[0] + 1;
    S[S[0]] = val;
}
int pop(int *S){
    S[0] = S[0] - 1;
    return S[S[0]+1];
}
int empty(int *S){
    return S[0] == 0;
}
int full(int *S){
    return S[0] == MAX*2;
}
void print(int *S){
    int val;
    if (empty(S)) return;

    val = pop(S);
    printf("%d | ", val);
    print(S);
    push(S, val);
}

void multiply(int *S){
    int val;
    if (empty(S) || full(S)) return;

    val = pop(S);
    multiply(S);
    push(S, val);
    push(S, val);
}
