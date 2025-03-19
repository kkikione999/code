#ifndef LLIST_H__
#define LLIST_H__
#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2

typedef void llist_op(const void * temp);
typedef int llist_cmp(const void*, const void*);
struct llist_node_st
{
    void* data;
    struct llist_node_st *prev;
    struct llist_node_st *next;

};

typedef struct
{
    int size;
    struct llist_node_st head;
}LLIST;

LLIST *llist_creat(int initsize);
void llist_destory(LLIST* ptr);
int llist_insert(LLIST *ptr, const void *data, int mode);
void llist_travel(LLIST* ptr, llist_op* op);
int llist_delete(LLIST* ptr, void* key, llist_cmp* cmp_func);
int llist_fetch(LLIST* ptr, void* key, llist_cmp* cmp_func, void *data);
void *llist_find(LLIST* ptr, void* cmp_data, llist_cmp* cmp_func);
#endif
