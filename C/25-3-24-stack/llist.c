#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

LLIST* llist_create(int initsize)
{
    LLIST *new;
    new = malloc(sizeof(LLIST));
    if(new == NULL)
        return NULL;
    new->size = initsize;
    new->head.next = &new->head;
    new->head.prev = &new->head;
   return new;
}

void llist_destroy(LLIST* ptr)
{
    struct llist_node_st *cur, *next;
    for(cur = ptr->head.next; cur != &ptr->head; cur = next )
    {
        next = cur->next;
        free(cur);
    }
    free(ptr);
}


int llist_insert(LLIST *ptr, const void *data, int mode)
{
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


void llist_travel(LLIST *ptr, llist_op *op)
{
    struct llist_node_st *cur;
    for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        op(cur->data);
    }
}


static struct llist_node_st * find_(LLIST *ptr,const void *key, llist_cmp *cmp)
{
    struct llist_node_st *cur;
    for(cur = ptr->head.next; cur->next != &ptr->head; cur = cur->next)
    {
        if(cmp(key,cur->data) == 0)
            break;
    }
    return cur;
}

void* llist_find(LLIST *ptr, const void *key, llist_cmp *cmp)
    {
        struct llist_node_st * p = find_(ptr, key, cmp);
        if(p == &ptr->head)
            return NULL;
        
        return p->data;
    }
int llist_delete(LLIST* ptr, void* key, llist_cmp* cmp_func)
{
    struct llist_node_st* p;
    p = find_(ptr, key, cmp_func);
    if(p == &ptr->head)     
        return -1;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return 0;
}

int llist_fetch(LLIST* ptr, void* key, llist_cmp* cmp_func, void *data)
{
    struct llist_node_st* p;
    p = find_(ptr, key, cmp_func);
    if(p == &ptr->head)     
        return -1;
    
    if(data != NULL)
        memcpy(data, p->data, ptr->size);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return 0;
}



