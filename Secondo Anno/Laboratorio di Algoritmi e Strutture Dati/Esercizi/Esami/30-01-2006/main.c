#include <time.h>

//#include "esercizio1.h"
//#include "esercizio2.h"
#include "esercizio3.h"

int main() {
    struct nodo *T1 = NULL;
    struct nodo *T2 = NULL;
    int val;

    srand(time(NULL));

    for (int i = 0; i < 10; i++){
        //val = (rand() % (20 - 1)) + 1;
        printf("Valore %d: ", i);
        scanf("%d", &val);
        tree_insert(&(T1), val);
        //val = (rand() % (20 - 1)) + 1;
        //tree_insert(&(T2), val);
    }

    printf("Albero 1:\n");
    preorder_visit(T1);
    //printf("\nAlbero 2:\n");
    //preorder_visit(T2);

    return 0;
}
