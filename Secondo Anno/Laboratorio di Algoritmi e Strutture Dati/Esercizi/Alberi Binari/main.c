#include "BTreeLibrary.h"

struct list{
    int data;
    struct list *next;
};

struct list *generate_list(){
    struct list *head, *temp;
    head = (struct list *)malloc(sizeof(struct list));
    head->data = 1;
    temp = head;
    for (int i = 2; i <= 10; i++){
        temp->next = (struct list *)malloc(sizeof(struct list));
        temp = temp->next;
        temp->data = i;
    }
    temp->next = NULL;
    return head;
}
void print_list(struct list *l){
    while (l != NULL){
        printf("%d | ", l->data);
        l = l->next;
    }
}
void remove_odds(struct list **head, struct node **root){
    struct list *current, *next;

    while ((*head)->data % 2 == 0 && head != NULL)
        *head = (*head)->next;

    current = *head;
    next = current->next;
    insert(root, next->data);
    free(current->next);

    while(next){
        if (next->data % 2 == 0) next = next->next;
        else{
            current->next = next;
            current = next;
            next = next->next;
            insert(root, current->next->data);
            free(current->next);
        }
    }
}

int main() {
    struct node *root = NULL;
    int n_elem, val;

    struct list *list = NULL;

    printf("How many values? ");
    scanf("%d", &n_elem);

    for (int i = 0; i < n_elem; i++){
        do{
            printf("Value: ");
            scanf("%d", &val);
            if (val <= 0) printf("\nOnly values > 0\n");
        } while(val <= 0);
        dp_insert(&(root), val);
    }

    printf("\nVisiting tree with order visit:\n");
    order_visit(root);

    printf("\nItem to find: ");
    scanf("%d", &val);
    if (find(root, val)) printf("Item found!\n");
    else printf("Item not found\n");

    printf("The minimum value in the tree is: %d\n", find_minimum(root));

    printf("Item to remove: ");
    scanf("%d", &val);
    remove_node(&root, val);
    order_visit(root);
    return 0;
}
