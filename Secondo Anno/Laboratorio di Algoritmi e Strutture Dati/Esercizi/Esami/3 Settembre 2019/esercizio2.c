#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int key;
    struct nodo *left;
    struct nodo *right;
};

int empty(struct nodo *root){
    return root == NULL;
}
void insert(struct nodo **root, int val){
    struct nodo *temp;
    if (empty(*root)){
        temp = (struct nodo *)malloc(sizeof(struct nodo));
        temp->key = val;
        temp->left = NULL;
        temp->right = NULL;
        *root = temp;
    }
    else if (val < (*root)->key) insert(&(*root)->left, val);
    else if (val > (*root)->key) insert(&(*root)->right, val);
}

void stampa_in_postordine(struct nodo *root){
    if (root){
        stampa_in_postordine(root->left);
        stampa_in_postordine(root->right);
        printf("%d | ", root->key);
    }
}

int checkABR_aux(struct nodo *root, struct nodo **prev){
    if (root == NULL) return 1;
    int check_left = checkABR_aux(root->left, prev);

    if (*prev != NULL && root->key < (*prev)->key) return 0;
    *prev = root;
    int check_right = checkABR_aux(root->right, prev);

    if (check_left && check_right) return 1;

    return 0;
}
int checkABR(struct nodo *root){
    if (root == NULL) return 0;
    struct nodo *prev = NULL;
    return checkABR_aux(root, &(prev));
}

int tree_equal(struct nodo *t1, struct nodo *t2){
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;

    return (t1->key == t2->key
            && tree_equal(t1->left, t2->left)
            && tree_equal(t1->right, t2->right));
}

int check_subtree(struct nodo *t1, struct nodo *t2){
    if (t1 == NULL) return 0;
    if (t2 == NULL) return 1;
    if (tree_equal(t1, t2)) return 1;
    return check_subtree(t1->left, t2) || check_subtree(t1->right, t2);
}

int main() {
    struct nodo *T1 = NULL;
    struct nodo *T2 = NULL;

    insert(&(T1), 3);
    insert(&(T1), 1);
    insert(&(T1), 7);
    insert(&(T1), 5);
    insert(&(T1), 9);
    insert(&(T1), 4);
    insert(&(T1), 8);
    insert(&(T1), 6);
    insert(&(T1), 2);

    insert(&(T2), 9);
    insert(&(T2), 4);
    insert(&(T2), 8);
    insert(&(T2), 6);
    insert(&(T2), 2);

    stampa_in_postordine(T1);
    printf("\n");
    stampa_in_postordine(T2);

    if (checkABR(T1)) printf("\nT1 ABR");
    else printf("\nT1 non ABR");

    if (checkABR(T2)) printf("\nT2 ABR");
    else printf("\nT2 non ABR");

    if (check_subtree(T1, T2)) printf("\nT2 sottoalbero di T1");
    else printf("\nT2 non sottoalbero di T1");

    return 0;
}
