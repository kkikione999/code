#ifndef LIST_H__

#define LIST_H__

typedef struct node {
    int number;
    struct node *next;
} node_st;

node_st *jose_create(int num);
//int jose_insert(node_st *head, int number);
//void jose_delete(node_st *head, int number);
void jose_print(node_st *me);
void jose_destroy(node_st *me);
void jose_free(node_st *me);
//void jose_kill(node_st *me, int m);
void jose_delete(node_st **me, int number);
void jose_delete2(node_st **me, int number);
#endif // LIST_H__
