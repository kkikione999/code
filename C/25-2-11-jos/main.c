#include <stdio.h>
#include "list.h"

int main(void)
{
	node_st* me = jose_create(5);
	printf("creat finish\n");

	node_st* curr = me;
	for (int i = 0; i < 5; i++) {
		printf("%d\n", curr->number);
		curr = curr->next;
	}

	jose_destroy(me);
	
    return 0;
}
