#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree_st* tree_create(char data)
{
    tree_st* head = malloc(sizeof(tree_st));
    if (head == NULL)       
    {
        return NULL;
    }
    
    head->data = data;
    head->lchild = NULL;
    head->rchild = NULL;
    return head;
}


void tree_destory(tree_st* ptr)
{
    if(ptr == NULL)
        return ;
    
    tree_destory(ptr->lchild);
    tree_destory(ptr->rchild);
    free(ptr);
}

void tree_print(tree_st * ptr)
{
    if(ptr == NULL)
        return ;

    printf("%c ", ptr->data);
    tree_print(ptr->lchild);
    tree_print(ptr->rchild);
}

void tree_insert(tree_st* ptr, char data)
{
    if(ptr == NULL)
        return ;
    
    if(ptr->lchild == NULL)
    {
        ptr->lchild = tree_create(data);
    }
    else if(ptr->rchild == NULL)
    {
        ptr->rchild = tree_create(data);
    }
    else
    {
        tree_insert(ptr->lchild, data);
    }
}