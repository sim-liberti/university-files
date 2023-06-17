#include "BTreeLibrary.h"

int empty(struct node *n){
    return (n != NULL) ? 0 : 1;
}
int get_node_value(struct node *n, int *val){
    int is_empty = 1;
    if (!empty(n)){
        *val = n->data;
        is_empty = 0;
    }
    return is_empty;
}
struct node *get_left(struct node *n){
    struct node *temp = NULL;
    if (!empty(n)) temp = n->left;
    return temp;
}
struct node *get_right(struct node *n){
    struct node *temp = NULL;
    if (!empty(n)) temp = n->right;
    return temp;
}
struct node *create_tree(struct node *l, struct node *r, int data){
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp){
        temp->data = data;
        temp->left = l;
        temp->right = r;
    }
    return temp;
}
void preorder_visit(struct node *root){
    if (root){
        printf("%d", root->data);
        preorder_visit(root->left);
        preorder_visit(root->right);
    }
}
void order_visit(struct node *root){
    if (root){
        order_visit(root->left);
        printf("%d", root->data);
        order_visit(root->right);
    }
}
void postorder_visit(struct node *root){
    if (root){
        postorder_visit(root->left);
        postorder_visit(root->right);
        printf("%d", root->data);
    }
}
int binary_search(struct node *root, int val){
    int found = 0;
    if (!empty(root)){
        if (root->data == val) found = 1;
        else if (val < root->data)
            found = binary_search(root->left, val);
        else
            found = binary_search(root->right, val);
    }
    return found;
}
struct node *insert(struct node *root, int val){
    struct node *temp;

    if (empty(root)){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    else if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}
void dp_insert(struct node **root, int val){
    struct node *temp;
    if (empty(*root)){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        *root = temp;
    }
    else if (val < (*root)->data)
        dp_insert(&(*root)->left, val);
    else if (val > (*root)->data)
        dp_insert(&(*root)->right, val);
}
int find_minimum(struct node *root){
    int min = 0;
    if (!empty(root)){
        if (root->left == NULL) min = root->data;
        else min = find_minimum(root->left);
    }
    return min;
}
int find(struct node *root, int val){
    int found = 0;
    if (!empty(root)){
        if (root->data == val) found = 1;
        else if (val < root->data) found = find(root->left, val);
        else found = find(root->right, val);
    }
    return found;
}
void remove_node(struct node **root, int val){
    struct node *temp;
    temp = *root;

    if (!(*root)){
        if (val < (*root)->data)
            remove_node(&((*root)->left), val);
        else if (val > (*root)->data)
            remove_node(&((*root)->right), val);
        else {
            if (!((*root)->left) && !((*root)->right)) { /*val è una foglia*/
                free(*root);
                *root = NULL;
            }
            if (((*root)->left) && (!((*root)->right))) /*dx è vuoto*/
                *root=temp->left;
            if (((*root)->left) && (!((*root)->right))) /*sx è vuoto*/
                *root=temp->right;
            if ((temp->right==NULL) || (temp->left==NULL)){ /*se un sotto-abr è vuoto*/
                free(temp);
                return;
            }
            if (((*root)->left) && ((*root)->right)){ /*se dx e sx non sono vuoti*/
                (*root)->data = find_minimum((*root)->right);
                remove_node(&(*root)->right, (*root)->data);
            }
        }
    }
}
