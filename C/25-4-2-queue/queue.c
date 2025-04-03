#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


q_node * queue_node_create(int data)
{
    q_node * newnode = malloc(sizeof(q_node));
    if(newnode == NULL)
    {
        exit(-1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

queue* queue_create(void)
{
    queue * q = malloc(sizeof(queue));
    if(q == NULL)
    {
        exit(-1);
    }
    q->front = q->rear = NULL;
    return q;
}

bool isqueueEmpty(queue * q)
{
    if (q->front == NULL) 
    {
        return true;
    }
    else
        return false;
    
}

void equeue(queue * que, int data)
{
    q_node* newnode = queue_node_create(data);
    if(newnode == NULL)
        exit(-1);
    if( isqueueEmpty(que) == true)
    {
        que->front = newnode;
        que->rear = newnode;
    }
    else
    {
        que->rear->next = newnode;
        que->rear = newnode;
    }
}

int dequeue(queue* que)
{
    if(isqueueEmpty(que) == true)
        return 0;
    q_node * temp_node = que->front;
    que->front = que->front->next;
    int data = temp_node->data;
    free(temp_node);
    return data;
}

void queue_destory(queue* que)
{
    while (que->front != NULL)
    {
        dequeue(que);
    }
}

void queue_travle(queue* que)
{
    q_node* temp = que->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}