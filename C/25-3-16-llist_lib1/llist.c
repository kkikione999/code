#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"


LLIST *llist_creat(int initsize)//头节点记录用户data数据的大小
{
    LLIST* new = malloc(sizeof(LLIST));
    if(new == NULL)
        return NULL;
    new->size = initsize;
    new->head.next = &new->head;
    new->head.prev = &new->head;
    new->head.data = NULL;
    return new;
}

void llist_destory(LLIST* ptr)
{
    struct llist_node_st *cur, *tmp;
    for(cur = ptr->head.next;cur != &ptr->head; cur = tmp)
    {
        tmp = cur->next;
        free(cur->data); //容易遗漏
        free(cur);
    }
    free(ptr);

}

int llist_insert(LLIST *ptr, const void *data, int mode)
{
    struct llist_node_st* newnode;
    newnode = malloc(sizeof(struct llist_node_st));//第一次malloc
    if(newnode == NULL)
        return -1;

    newnode->data = malloc(ptr->size);//第二次malloc
    if(newnode->data == NULL)//第二次malloc不成功要把第一次malloc给free掉
    {
        free(newnode);
        return -2;
    }
    memcpy(newnode->data, data, ptr->size);//数据的存储要用memcpy，因为不知道用户数据类型
    
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
    else//如果别人传进的是未知的插入方式也要把来两次malloc给free掉
    {
        free(newnode->data);
        free(newnode);
        return -3;
    }
    newnode->prev->next = newnode;
    newnode->next->prev = newnode;
    return 0;

}


void llist_travel(LLIST* ptr, llist_op* op)
{
    struct llist_node_st *cur;
    
    for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        op(cur->data);
    }

}
//找不到返回头节点，找到返回数据节点
//需要用户写一个回调函数，用户来判断有没有找到
static struct llist_node_st* find_(LLIST* ptr, void* cmp_data, llist_cmp* cmp_func)
{
    struct llist_node_st *cur;
    for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
    {
        if(cmp_func(cmp_data, cur->data) == 0)
            break;
    }
    return cur;
}

void *llist_find(LLIST* ptr, void* cmp_data, llist_cmp* cmp_func)
{
    return find_(ptr, cmp_data, cmp_func)->data;
}

int llist_delete(LLIST* ptr, void* key, llist_cmp* cmp_func)
{
    struct llist_node_st* p;
    p = find_(ptr, key, cmp_func);//先找到目标数据
    if(p == &ptr->head)//找不到目标数据返回
        return -1;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p->data);//记得把data给free掉
    free(p);
    return 0;
}

int llist_fetch(LLIST* ptr, void* key, llist_cmp* cmp_func, void *data)
{
    struct llist_node_st* p;
    p = find_(ptr, key, cmp_func);//先找到目标数据
    if(p == &ptr->head)//找不到目标数据返回 
        return -1;
    
    if(data != NULL)
        memcpy(data, p->data, ptr->size);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p->data);//记得把data给free掉
    free(p);
    return 0;

}
