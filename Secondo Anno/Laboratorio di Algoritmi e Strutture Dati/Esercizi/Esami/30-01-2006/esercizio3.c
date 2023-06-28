//
// Created by simli on 6/18/2023.
//

#include "esercizio3.h"
int empty(struct nodo *root){
    return root == NULL;
}
void tree_insert(struct nodo **root, int val){
    struct nodo *temp;
    if (empty(*root)){
        temp = (struct nodo *)malloc(sizeof(struct nodo));
        temp->left = NULL;
        temp->right = NULL;
        temp->inforadice = val;
        *root = temp;
    }
    else if (val < (*root)->inforadice) tree_insert(&(*root)->left, val);
    else if (val > (*root)->inforadice) tree_insert(&(*root)->right, val);
}
void preorder_visit(struct nodo *root){
    if (root){
        printf("%d | ", root->inforadice);
        preorder_visit(root->left);
        preorder_visit(root->right);
    }
}