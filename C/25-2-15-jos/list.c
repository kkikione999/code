#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_st* jose_create(int num)
{
	int i = 1;
	node_st* me, *new_node = NULL;
	me = malloc(sizeof(node_st));
	if(me == NULL)
		return NULL;
	me->number = i++;
	me->next = me;
	node_st* curr = me;
	for(; i<=num; i++)
	{
		new_node = malloc(sizeof(node_st));
		if(new_node == NULL)
			return NULL;
		new_node->number = i;
		new_node->next = me;
		curr->next = new_node;
		curr = new_node;
	}
	return me;
}

void jose_print(node_st *me)
{
	node_st* list = me;
	do
	{
		printf("%d ", list->number);
		list = list->next;
	}while(list != me);
	printf("\n");
	return ;

}
void jose_delete(node_st **me, int number)
{
    node_st* list = *me;
    node_st* prev = NULL;
    if (number < 0)
    {
        printf("number is invalid\n");
        return;
    }

    // If the node to be deleted is the first node
    if (list->number == number)
    {
        // Traverse to the last node
        while (list->next != *me)
        {
            list = list->next;
        }
        // Point the last node to the next node of the head
        list->next = (*me)->next;
        // Update the head (*me) and free the old head
        node_st* new_head = (*me)->next;
        free(*me);
        *me = new_head;  // Update the head to the new head
        return;
    }

    // If the node to be deleted is a middle node
//    while (list->number != number && list->next != *me)
	while(list->next != *me && list->number != number)
    {
        prev = list;
        list = list->next;
    }

    if (list->number == number)
    {
        prev->next = list->next;
        free(list);
        return;
    }

    printf("number is not found\n");
}

void jose_kill(node_st *me, int m)
{
	node_st* list = me;
	node_st* prev = NULL;
	while(list->next != list)
	{
		for(int i=1; i<m; i++)
		{
			prev = list;
			list = list->next;
		}
		prev->next = list->next;
		printf("kill %d\n", list->number);
		free(list);
		list = prev->next;
	}
	printf("survive %d\n", list->number);
	return;
}

//free整个循环链表
void jose_free(node_st *me)
{
	node_st* list = me;
	node_st* next = NULL;
	do
	{
		next = list->next;
		free(list);
		list = next;
	}while(list != me);
	printf("free finished\n");
	return;
}

void jose_destroy(node_st *me)
{
	node_st* list = me;
	node_st* next = NULL;
	do
	{
		next = list->next;
		free(list);
		list = next;
	}while(list != me);
	printf("destroy finished\n");
	return;
}

