#ifndef NODE_H__
#define NODE_H__
typedef struct node 
{
    int coef;   //系数
    int exp;    //指数
    struct node *next;
}node_st;

node_st *create_list();
//添加一个节点
int add_node(node_st* me, int coef, int exp);
//打印链表
void print_list(node_st *me);
//释放链表
void free_list(node_st *me);


#endif
