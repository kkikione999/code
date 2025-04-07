#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode* next; /*"LINK_node*" 是一种以结构体为指针的数据类型 */

    /*以下是典型错误*/
    //LINK_node* next;
    /*如果 typedef 声明在结构体定义之后，就会出现编译错误，因为编译器在解析 LINK_node 时还不认识这个类型。*/
   /* 正确的顺序应该是先声明 struct LinkNode，然后使用 typedef 来定义别名*/

} LINK_node;

/*在此之后LINK_node == struct LinkNode*/

/*或者以下形式*/
// struct LinkNode
// {
//     int data;
//     struct LinkNode* next; /*"struct LinkNode*" 是一种以结构体为指针的数据类型 */
// };

void test()
{
    LINK_node node1 = {10 ,NULL};
    LINK_node node2 = {20 ,NULL};
    LINK_node node3 = {30 ,NULL};
    LINK_node node4 = {40 ,NULL};
    LINK_node node5 = {50 ,NULL};
    LINK_node node6 = {60 ,NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    

    struct LinkNode* pCurrent = &node1;
    while (pCurrent != NULL)
    {
        printf("%d ",pCurrent->data);

        pCurrent = pCurrent->next;      /*使用 -> 访问结构体成员: pCurrent是指针，指向结构体node1，pCurrent->next == node1.next*/

        
    }
     
    
}
/*------------------------------------------------*/
/*指针的运用*/
//现在main函数里面有一个名为head的指针
//要求：change_point(参数自己写)的函数能够修改head所指向的地址

/*如何理解int** pHead*/
//int** p 表示一个指向 int* 的指针，也就是一个二级指针。

void change_point(int** pHead)
{

}

int _mian(void)
{
    int* head;
    change_point(&head); //int ** 表示一个二级指针，指向指针的指针，所以要取指针的地址
}

typedef struct _node
{
    int value;
    struct _node* next;
}Node;

/*------------------------------------------------*/

/*面对链表，工程通常这样子做*/
typedef struct Node_list
{
    Node* head;
    Node* tail;
}List;

void add(List* pList, int number);
int main()
{
    List list;
    list.head = list.tail = NULL;
    int number;
    do
    {
        scanf("%d", &number);
        if (number!=-1)
        {
            add(&list, number);
        }
        
    } while ( number!=-1 );
    

    return 0;

}

void add(List* pList, int number)
{
    Node* p = (Node*)malloc(sizeof(Node));      //新建一个
    p->value = number;
    p->next = NULL;
    Node* last = pList->head;
    if( last )
    {
        printf("if_here\n");
        while (last->next)
        {
            last = last->next;
        }
        last->next = p;
    }else{
        pList->head = p;
        printf("else_here\n");
    }
}