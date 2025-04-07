#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"



int main()
{
    sqlist *list;
    //list = sqlist_create();
    datatype arr[] = {22,33,45,88};
    sqlist_create1(&list);
    if(list == NULL)
    {
        fprintf(stderr,"err\n");
    }

    for(size_t i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        if(sqlist_insert(list, i, &arr[i]) != 0)
        {
            fprintf(stderr, "err\n");
        }
    }

    sqlist_display(list);
    printf("last is %d\n", list->last);
    sqlist_destroy(list);
    return 0;
}

