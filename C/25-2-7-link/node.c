#include<stdio.h>
#include<stdlib.h>
#include "node.h"


//创建一个有头节点的链表
node_st *create_list()
{
    node_st *head = (node_st *)malloc(sizeof(node_st));
    head->next = NULL;
    if(head == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }
    return head;
}

//添加一个节点
int add_node(node_st* me, int coef, int exp)
{
    node_st *new = (node_st *)malloc(sizeof(node_st));

    node_st* curr = me;
    if(new == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }
    new->coef = coef;
    new->exp = exp;
    new->next = NULL;

    //如果链表为空或者新节点的指数小于链表中的第一个最小指数
    if(me->next == NULL || me->next->exp > exp)
    {   
        new->next = me->next;
        me->next = new;
        return 0;
    }

    while (curr->next != NULL && curr->next->exp < exp) 
    {
        curr = curr->next;
    }
    #if 0
    if(curr->next != NULL && curr->next->exp == exp)
    {
        curr->next->coef += coef;
        free(new);
        return 0;
    }
    curr->next = new;
    return 0;
    #endif
    if(curr->next != NULL && curr->next->exp == exp)
    {
        curr->next->coef += coef;
        free(new);
        return 0;
    }
    new->next = curr->next;
    curr->next = new;
    return 0;
}

//打印链表
void print_list(node_st *me)
{
    node_st *curr = me->next;
    while(curr != NULL)
    {
        printf("%dX^%d", curr->coef, curr->exp);
        if(curr->next != NULL)
        {
            printf("+");
        }
        curr = curr->next;
    }
    printf("\n");
}


//释放链表
void free_list(node_st *me)
{
    node_st *curr = me->next;
    while(curr != NULL)
    {
        node_st *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(me);
}

