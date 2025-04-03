#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"


int main ()
{
    int arr[] = {1,2,3,4,5,6};
    queue* q = queue_create();
    for (int i = 0; i < sizeof(arr)/sizeof (arr[0]); i++)
    {
        equeue(q, arr[i]);   
    }
    queue_travle(q);
    printf("dequeue %d\n", dequeue(q));
    printf("dequeue %d\n", dequeue(q));
    queue_travle(q);
    queue_destory(q);
    if(isqueueEmpty(q) == true)
        printf("destory successed!\n");
    else
        printf("destory filed\n");
    exit(0);
}