#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

sqlist* sqlist_create()
{
    sqlist *me;
    me = malloc(sizeof(*me));
    if (me == NULL)
    {
        return NULL;
    }
    me->last = -1;
    return me;
}


void sqlist_create1(sqlist ** ptr)
{
    *ptr = malloc(sizeof(**ptr));
    if(*ptr == NULL)
    {
        return;
    }
    (*ptr)->last = -1;
    return ;

}
int sqlist_insert(sqlist *me,int i, datatype *data)
{
    int j;
    if(i > DATASIZE-1)
        return -1;
    if(i<0 || i> me->last+1)
        return -2;
    
    // for(j = me->last; j<i; j--)
    // {
    //     me->data[j+1] = me->data[j];
    // }
    for(j = me->last; i<=j; j--)
        me->data[j+1] = me->data[j];
    me->data[i] = *data;
    me->last ++;
    return 0;

}

int sqlist_destroy(sqlist *me)
{
    free(me);
    return 0;
}

#if 0
int sqlist_find(sqlist *, datatype)
int sqlist_setempty(sqlist *)
int sqlist_getnum(sqlist *)
int sqlist_union(sqlist *)
int sqlist_delete(sqlist *, int i)
#endif
void sqlist_display(sqlist *me)
{
    if(me->last == -1)
        return ; 
    for(int i = 0; i<=me->last; i++)
    {
        
        printf("me.data[%d] is %d\n",i, me->data[i]);
    }
    printf("\n");
}

