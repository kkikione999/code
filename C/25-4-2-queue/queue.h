#ifndef QUEUE_H__
#define QUEUE_H__
#include <stdbool.h>
typedef struct queue_node
{
    int data;
    struct queue_node * next;
}q_node;

typedef struct Queue
{
    q_node* front;
    q_node* rear;
}queue;

q_node * queue_node_create(int data);

queue* queue_create(void);

bool isqueueEmpty(queue * q);

void equeue(queue * que, int data);

int dequeue(queue* que);

void queue_destory(queue* que);
void queue_travle(queue* que);



#endif
