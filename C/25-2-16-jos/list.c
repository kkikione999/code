#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_st* jose_create(int num)
{
	if(num < 1)
		return NULL;
	int i = 1;
	node_st* head = malloc(sizeof(node_st));
	node_st* newnode = NULL, *curr = NULL;
	if(head == NULL)
		return NULL;
	head->next = head;
	head->number = i++;
	if(num == 1)
		return head;
	curr = head;
	printf("fine\r\n");
	for(;i <= num; i++)
	{
		newnode = malloc(sizeof(node_st));
		if(newnode == NULL)
			return NULL;
		newnode->number = i;
		newnode->next = head;
		curr->next = newnode;
		curr = newnode;
	}
	return head;

}

void jose_print(node_st *me)
{
	node_st* list = me;
	do
	{
		printf("%d ", list->number);
		list = list->next;
	}while (list!=me);
	printf("\n");
}
void jose_delete(node_st **me, int number)
{
	node_st *list = *me;
	node_st *prev = NULL;
	if((*me)->number == number)
	{
		while(list->next != *me)
		{
			list = list->next;
		}
		list->next = (*me)->next;
		node_st* new_head = (*me)->next;
		free(*me);
		*me = new_head;
		return ;
	}

	//如果要删除的节点在中间
//	while (list->number != number && list->next != *me)
	while(list->next != *me && list->number != number)
	{
		prev = list;
		list = list->next;
	}
	if(list->number == number)
	{
		prev->next = list->next;
		free(list);
		return ;
	}
	printf("the list without this number\n");
	
}

// void jose_kill(node_st *me, int m)
// {
// 	node_st* list = me;
// 	node_st* prev = NULL;
// 	while(list->next = list)
// 	{
// 		for(int i=1; i<m; i++)
// 		{
// 			prev = list;
// 			list = list->next;
// 		}
// 		prev->next = list->next;
// 		printf("kill %d\n", list->number);
// 		free(list);
// 		list = prev->next;
// 	}
// 	printf("survive %d\n", list->number);
// 	return;
// }

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

