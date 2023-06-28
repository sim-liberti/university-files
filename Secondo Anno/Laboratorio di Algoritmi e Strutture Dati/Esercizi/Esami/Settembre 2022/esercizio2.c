#include "esercizio2.h"

int vuoto(struct nodo *root){
    return root == NULL;
}
void visita_preordine(struct nodo *root){
    if (vuoto(root)) return;
    visita_preordine(root->left);
    visita_preordine(root->right);
    printf("%d | ", root->key);
}
void inserisci_nodo(struct nodo **root, int key){
    struct nodo *temp;
    if (*root == NULL){
        temp = (struct nodo *)malloc(sizeof(struct nodo));
        if (temp){
            temp->key = key;
            temp->left = temp->right = NULL;
            *root = temp;
        }
        else printf("Errore di allocazione del nodo\n");
    }
    else if(key < (*root)->key) inserisci_nodo(&(*root)->left, key);
    else if(key > (*root)->key) inserisci_nodo(&(*root)->right, key);
}
int controllo_abr(struct nodo *root){
    if (root == NULL) return 1;

    /* falso se il massimo è a sinistra */
    if (root->left != NULL && root->key < cerca_massimo(root->left)) return 0;
    /* falso se il minimo è a destra */
    if (root->right != NULL && root->key > cerca_minimo(root->right)) return 0;
    /* falso ricorsivamente per i due sottoalberi */
    if (!controllo_abr(root->left) || !controllo_abr(root->right)) return 0;

    return 1;
}
int cerca_minimo(struct nodo *root){
    int min = 0;
    if (!vuoto(root)){
        if (root->left == NULL) min = root->key;
        else
            min = cerca_minimo(root->left);
    }
    return min;
}
int cerca_massimo(struct nodo *root){
    int min = 0;
    if (!vuoto(root)){
        if (root->right == NULL) min = root->key;
        else
            min = cerca_massimo(root->right);
    }
    return min;
}
void controlla_abr_stampa_minimo(struct nodo *root){
    if (!controllo_abr(root)) printf("\nL'albero non è un ABR\n");
    else printf("\nL'albero è un ABR\n");
    printf("Il valore minimo dell'albero è: %d", cerca_minimo(root));
}
