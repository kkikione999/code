#include <stdlib.h>

typedef struct node_st
{
    int data;
    struct node* next;
}Node;

Node* list_Node_creat(void)
{
    Node* me = NULL
    me = malloc(sizeof(me));
    if(me)
    {
        //报错
    }
    else
        return me;
}

int list_insert(Node* me, int data)
{
    Node* new_node = NULL, *current = me;
    while (current->data < data && current->next)
    {     
        
    }
    new_node->next = current->next;
    current->next = new_node;
    new_node->data = data;
    
}
//me为空指针
//me只有一个元素
int list_delect(Node* me, int data)
{
    Node* current = me->next, *temp= NULL;
    if(current == NULL)
    {
        //me是空链表
        return -1;
    }
    while (current->next && current->next->data != data)
    {
        current = current->next;
    }
    if(current->data == data)
    {
        
        free(current);
    }
       
}

int list_distory(Node* me)
{
    Node* current = me->next, *tmp = NULL;
    while(temp = current->next)
    {
        free(current);
    }
    free(me);
}

void list_display(Node* me)
{
    Node* current = me->next;
    while (current->next&&current)
    {
        printf("%d   ", current->data);
        current = current->next;
    }
    printf("\n");
    return ;
}


