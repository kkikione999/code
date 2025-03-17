#include <stdio.h>
#include "list.h"

int main(void)
{
    node_st *head = NULL;
    head = jose_create(6);
    if (head == NULL) {
        return 1;
    }
    
    // jose_insert(&head, 1);
    // printf("here\n");
    // jose_insert(&head, 2);
    // jose_insert(&head, 3);
    // jose_insert(&head, 4);
    // jose_insert(&head, 5);
    jose_print(head);
    jose_delete(&head, 2);
    //jose_print(head);
    jose_destroy(&head);
    return 0;
}