#ifndef LIST_H__
#define LIST_H__

typedef struct list {
    int data;
    struct list *next;
} List;

int list_insert(List *head, int data);
int list_insert_head(List *head, int data);
int list_insert_order(List *head, int data);
int list_delete(List *head, int data);
void list_show(List *head);
List* list_create(void);
void list_destroy(List *head);


#endif