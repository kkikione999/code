#ifndef TREE_H__
#define TREE_H__

typedef struct tree_node
{
    char data;
    struct tree_node * lchild;
    struct tree_node * rchild;
}tree_st;

tree_st* tree_create(char data);

void tree_destory(tree_st* ptr);

void tree_print(tree_st * ptr);

void tree_insert(tree_st* ptr, char data);

#endif
