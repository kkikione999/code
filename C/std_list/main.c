#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
    List *head = list_create();
    if(head == NULL)
    {
        printf("list_create failed\n");
        return -1;
    }
    
    int num[] = {3,23,2,35,12,21,77,44,41,4,5,7};

    for(int i = 0; i < sizeof(num)/sizeof(num[0]); i++)
    {
        list_insert(head, num[i]);
    }

    list_show(head);

    list_delete(head, 77);

    list_show(head);
    
    return 0;
}