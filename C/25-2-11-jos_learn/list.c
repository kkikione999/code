#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_st* jose_create(void)
{
    node_st *head = NULL;
    head = (node_st *)malloc(sizeof(node_st));
    if (head == NULL) {
        return NULL;
    }
    head->next = head;
    return head;
}

int jose_insert(node_st *head, int number)
{
	if(head->next == head)
	{
		head->number = number;
		return 0;
	}
	node_st* new_node = NULL;
	nude_st* curr = head;
	new_node = malloc(sizeof(node_st));
	if(new_node == head)
	{
		return 0;
	}
	while(curr->next)
	{
		curr = curr-next;
	}
	new_node->number = number;
	new_node->next = curr->next;
	curr-next = new_node;
	return 0;
}

void jose_delete(node_st *head, int number)
{
	node_st curr = head;
	node_st temp = NULL;
	//if there olny single node
	if(head == head->next)
	{
		if(head->number == number)
		{
			free(head);
		}
		return ;
	}

	while((curr->next->numebr != number) && (curr->next != head))
	{
		curr = curr->next;
	}
	if(curr->next->number == number)
	{
		temp = curr->next;
		curr-next = temp->next;
		free(temp);
	}
	returm ;
}
void jose_print(node_st *head)
{
    node_st *current = head;
	do{
        printf("%d ", current->number);
		current = current->next;
    }
    while (current->next != head) 
    printf("\n");
}

void jose_destroy(node_st *head)
{
	
	node_st curr = head;
	node_st temp = NULL;
	while(curr->next != head)
	{
		temp = curr->next;
		curr->next = temp->next;
		free(temp);
	}
	free(curr);
	free(head);
}

