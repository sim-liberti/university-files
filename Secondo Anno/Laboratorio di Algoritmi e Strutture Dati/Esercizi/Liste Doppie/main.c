#include <stdio.h>
#include <stdlib.h>

#define ROWS 6

struct square{
    int data;
    struct square *top;
    struct square *right;
    struct square *bottom;
    struct square *left;
};

struct square *create_square(int val){
    struct square *s = (struct square *)malloc(sizeof(struct square));
    if (s != NULL){
        s->data = val;
        s->top = NULL;
        s->right = NULL;
        s->bottom = NULL;
        s->left = NULL;
    }
    return s;
}

struct square *create_board_util(struct square *current, int i, int j){
    struct square *temp;
    int val;

    if (i >= ROWS || j >= ROWS)
        return NULL;

    temp = create_square(0);
    temp->left = current;
    temp->top = current;
    temp->right = create_board_util(temp, i, j+1);
    temp->bottom = create_board_util(temp, i+1, j);

    return temp;
}

struct square *create_board(){
    return create_board_util(NULL, 0, 0);
}

void print_board(struct square *b){
    struct square *right;
    struct square *bottom = b;

    while (bottom){
        right = bottom;
        while (right){
            printf("| %d ", right->data);
            right = right->right;
        }
        printf("|\n");
        bottom = bottom->bottom;
    }

}

int main() {
    struct square *b = create_board();
    print_board(b);

    return 0;
}
