#include <stdlib.h>
#include <stdio.h>
#include <node.h>

typedef struct node 
{
    int coef;   //系数
    int exp;    //指数
    struct node *next;
}node_st;

node_st *create_list(void)
{
	node_st* me = malloc(sizeof(node_st));
	if(me == NULL)
		return NULL;
	me->next = NULL;
	return me;
}

int add_node(node_st* me, int coef, int exp)
{
	node_st new = malloc(sizeof(node_st));
	node_st *curr = me;
	if(new == NULL)
		return -1;
	new->coef = coef;
	new->exp = exp;
	new->next = NULL;

	if(me->next == NULL || me->next->exp > exp)
	{
		new->next = me->next;
		me->next = new;
	}

	while(curr->next != NULL && curr->next->exp < exp)
	{
		curr = curr->next;
	}
	
	new->next = curr->next;
	curr->next = new;
	return 0;
}

void print_list(node_st *me)
{
	node_st* curr = me->next;

	if(curr->NULL)
	{
		printf("the list is empty\r\n");
		return 0;
	}

	while(curr->next)
	{
		printf("coef = %d, exp = %d\n", cur->coef, cur->exp);
	}
	return ;
}

void free_list(node_st *me)
{
	node_st* curr = NULL;
	if(me->next == NULL)
	{
		free(me);
		return ;
	}
	do
	{
		curr->next = me->next:
		me->next = curr->next;
		free(curr);
	}
	while(curr->next == NULL)


	free(me);



}
