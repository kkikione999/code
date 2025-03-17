#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_st* jose_create(int num)
{
	if(num<1)
	{
		printf("the number is invalid\r\n");
		return	NULL;
	}
	int i = 1;
	
	node_st* head = NULL, *curr = NULL;
	head = malloc(sizeof(node_st));
	if(head == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	head->number = 1;
	head->next = NULL;
	curr = head;
	node_st* temp = NULL;
	printf("create before while\n");
	while(i<num)
	{
		node_st* new_node = malloc(sizeof(node_st));
		if(new_node == NULL)
		{
			printf("malloc filed \n");
			return NULL;
		}
		new_node->number = i+1;
		curr->next = new_node;
		new_node->next = head; // Ensure the new node points back to head
		curr = new_node;
		i++;
	}
	printf("create after while\n");
	return head;

}

void jose_print(node_st *me)
{
	node_st* curr = me;
	int i = 1;
	printf("print start\n");
	do
	{
		printf("node %d = %d\t", i++, curr->number);
		curr = curr->next;
	}while(curr != me);
	printf("print finish\n");
	return ;
}

void jose_destroy(node_st *me)
{
	node_st* temp = NULL;
	node_st* head = me;

	temp = head;
	while(head->next != head)
	{
		temp = head->next;
		head = temp->next;
		free(temp);
	}
	free(head);
	return ;
}

