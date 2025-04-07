#include "list.h"
#include <stdlib.h>
#include <stdio.h>
//创建头节点
List *list_create(void)
{
    List *head;
    head = malloc(sizeof(head));
    if(head == NULL)
        return NULL;
    head->next = NULL;
    return head;
}
//尾部插入
int list_insert(List *head, int data)
{
    List *newnode, *current = head;
    newnode = malloc(sizeof(newnode));
    if(newnode == NULL)
        return -1;
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    newnode->data = data;
    newnode->next = current->next;
    current->next = newnode;
    return 0;
}

//头部插入
int list_insert_head(List *head, int data)
{
    List *newnode;
    newnode = malloc(sizeof(newnode));
    if(newnode == NULL)
        return -1;
    newnode->data = data;
    newnode->next = head->next;
    head->next = newnode;
    return 0;
}

//按顺序插入
int list_insert_order(List *head, int data)
{
    List *newnode, *current = head;
    newnode = malloc(sizeof(newnode));
    if(newnode == NULL)
        return -1;
    while (current->next != NULL && current->next->data < data)
    {
        current = current->next;
    }
    newnode->data = data;
    newnode->next = current->next;
    current->next = newnode;
    return 0;
}

//删除
int list_delete(List *head, int data)
{
    List *current = head, *temp;
    while (current->next != NULL && current->next->data != data)
    {
        current = current->next;
    }
    if(current->next == NULL)
        return -1;
    temp = current->next;
    current->next = temp->next;
    free(temp);
    return 0;
}

//查找
List *list_find(List *head, int data)
{
    List *current = head->next;
    while (current != NULL && current->data != data)
    {
        current = current->next;
    }
    return current;
}

//打印
void list_show(List *head)
{
    List *current = head->next;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//销毁
void list_destroy(List *head)
{
    List *current = head->next, *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}



