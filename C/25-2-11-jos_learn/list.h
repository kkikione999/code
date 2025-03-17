#ifndef LIST_H__
#define LIST_H__

typedef struct node {
    int number;
    struct node *next;
} node_st;

node_st *jose_create(int n);
int jose_insert(node_st **head, int number);
void jose_delete(node_st **head, int number);
void jose_print(node_st *head);
void jose_destroy(node_st **head);


#endif // LIST_H__
