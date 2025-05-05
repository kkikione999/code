#include <stdio.h>
#include <stdlib>
#include "list.h"

typedef struct listnode
{
    int val;
    struct listnode *next;
    struct listnode *prev;
}Listnode;

typedef struct listhead
{
    int nums;
    struct listnode node;
}Listhead;


Listhead * create_List(void)
{
    Listhead * head = malloc(sizeof(Listhead));
    if(head == NULL)    return NULL;
    head->node.val = 0;
    head->node.next = &head->node;
    head->node.prev = &head->node;
    return head;
}
#define FRONT 1
#define BACK 0
/*insert_mode*/
int list_insert(Listhead* head, int val, int mode)
{
    Listnode * newnode = malloc(sizeof(Listnode));
    if(newnode == NULL) return -1;
    newnode->val = val;
    if(mode == FRONT)
    {
        newnode->next = head->node.next;
        newnode->prev = &head->node;
        head->node.next = newnode;
        head->node.next->prev = newnode;
    }
    else if(mode == BACK)
    {
        newnode->next = &head->node;
        newnode->prev = head->node.prev;
        head->node.prev->next = newnode;
        head->node.prev = newnode;
    }
    return 0;
    
}


void list_destory(void)
{

}

