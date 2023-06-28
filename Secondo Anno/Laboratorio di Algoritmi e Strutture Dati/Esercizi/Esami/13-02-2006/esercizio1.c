//
// Created by simli on 6/18/2023.
//

#include "esercizio1.h"

int empty_queue(int Q[]){
    return Q[0]==0;
}

int full_queue(int Q[]){
    return Q[0] == Q[MAX+1];
}

void enqueue (int Q[], int valore){

    if(Q[0] == 0)
        Q[0]=1;

    Q[Q[MAX+1]] = valore;

    Q[MAX+1] = (Q[MAX+1] % MAX) + 1;
}

int dequeue(int Q[]){
    int valore = Q[Q[0]];
    Q[0] = (Q[0] % MAX) + 1;

    if(Q[0] == Q[MAX+1])
    {
        Q[0] = 0;
        Q[MAX+1]=1;
    }

    return valore;
}

void reverse(int Q[]){
    int val = 1;

    if(empty_queue(Q))
        return;
    else
    {
        val=dequeue(Q);
        reverse(Q);
        enqueue(Q,val);
    }
}

void stampa_queue(int Q[]){
    int val = 1;

    if(empty_queue(Q))
        return;
    else
    {
        val=dequeue(Q);
        printf("%d|",val);
        stampa_queue(Q);
        enqueue(Q, val);
    }

}

void new_queue(int Q[]){
    int num_elementi;
    int valore = 0;
    printf("\nQuanti elementi (max%delementi): ", MAX);
    scanf("%d",&num_elementi);
    while(num_elementi>MAX)
    {
        printf("\nmax%delementi: ", MAX);
        scanf("%d",&num_elementi);
    }

    Q[MAX+1] = 1;   //LA PROVA CHE IL PROF NON SA COME FUNZIONA C

    while(num_elementi)
    {
        printf("Inserire un valore: ");
        scanf("%d",&valore);
        enqueue(Q, valore);
        num_elementi = num_elementi-1;
    }
}
