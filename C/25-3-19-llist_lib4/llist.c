#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"


struct llist_node_st {
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[];
};

struct llist_head_st{
    int size;
    struct llist_node_st head;
};

LLIST* llist_create(int initsize)
{
    struct llist_head_st *new;
    new = malloc(sizeof(LLIST));
    if(new == NULL)
        return NULL;
    new->size = initsize;
    new->head.next = &new->head;
    new->head.prev = &new->head;
   return new;
}

void llist_destroy(LLIST* p)
{
    struct llist_node_st *cur, *next;
    struct llist_head_st *ptr = p;
    for(cur = ptr->head.next; cur != &ptr->head; cur = next )
    {
        next = cur->next;
        free(cur);
    }
    free(ptr);
}


int llist_insert(LLIST *p, const void *data, int mode)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st* newnode;
    newnode = malloc(sizeof(struct llist_node_st) + ptr->size);
    if(newnode == NULL)
        return -1;
    memcpy(newnode->data, data, ptr->size);
    
    if(mode == LLIST_FORWARD)
    {
        newnode->prev = &ptr->head;
        newnode->next = ptr->head.next;
    }
    else if (mode == LLIST_BACKWARD)
    {
        newnode->prev = ptr->head.prev;
        newnode->next = &ptr->head;
    }
    else
    {
        free(newnode);
        return -3;
    }
    newnode->prev->next = newnode;
    newnode->next->prev = newnode;
    return 0;

}


void llist_travel(LLIST *p, llist_op *op)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st *cur;
    for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        op(cur->data);
    }
}


static struct llist_node_st * find_(struct llist_head_st *ptr,const void *key, llist_cmp *cmp)
{

    struct llist_node_st *cur;
    for(cur = ptr->head.next; cur->next != &ptr->head; cur = cur->next)
    {
        if(cmp(key,cur->data) == 0)
            break;
    }
    return cur;
}

void* llist_find(LLIST *p, const void *key, llist_cmp *cmp)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st * node = find_(ptr, key, cmp);
    if(node == &ptr->head)
        return NULL;
    return node->data;
}
int llist_delete(LLIST* p, void* key, llist_cmp* cmp_func)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st* node;
    node = find_(ptr, key, cmp_func);
    if(node == &ptr->head)     
        return -1;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 0;
}

int llist_fetch(LLIST* p, void* key, llist_cmp* cmp_func, void *data)
{
    struct llist_head_st *ptr = p;
    struct llist_node_st* node;
    node = find_(ptr, key, cmp_func);
    if(node == &ptr->head)     
        return -1;
    
    if(data != NULL)
        memcpy(data, node->data, ptr->size);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 0;
}


