//
// Created by simli on 6/16/2023.
//

#ifndef ALBERI_BINARI_BTREELIBRARY_H
#define ALBERI_BINARI_BTREELIBRARY_H

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

int empty(struct node *n);
struct node *get_left(struct node *n);
struct node *get_right(struct node *n);
struct node *create_tree(struct node *l, struct node *r, int data);
void preorder_visit(struct node *root);
void order_visit(struct node *root);
void postorder_visit(struct node *root);
int binary_search(struct node *root, int val);
struct node *insert(struct node *root, int val);
void dp_insert(struct node **root, int val);
int find_minimum(struct node *root);
int find(struct node *root, int val);
void remove_node(struct node **root, int val);

#endif //ALBERI_BINARI_BTREELIBRARY_H
