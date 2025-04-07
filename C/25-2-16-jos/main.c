#include <stdio.h>
#include "list.h"

int main(void)
{
	node_st* me = jose_create(7);
	printf("creat finish\n");
	jose_print(me);
	printf("print finish\n");
	//jose_free(me);
	//jose_kill(me, 3);
	jose_delete(&me, 1);
	jose_print(me);
	//jose_destroy(me);
	
    return 0;
}
