#ifndef LLIST_H__
#define LLIST_H__
#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2

typedef int llist_cmp(const void *, const void*);
typedef void llist_op(const void*);

struct llist_node_st {
    struct llist_node_st *prev;
    struct llist_node_st *next;
    char data[];
};

typedef struct llist_head{
    int size;
    struct llist_node_st head;
    int (*insert)(struct llist_head* , const void *, int );
    void (*travel)(struct llist_head *ptr, llist_op *op);
    void*(*find)(struct llist_head *ptr, const void *key, llist_cmp *cmp);
    int (*fetch)(struct llist_head *ptr, void* key, llist_cmp* cmp_func, void *data);
    int (*delete)(struct llist_head *ptr, void* key, llist_cmp* cmp_func);
} LLIST;

LLIST* llist_create(int initsize);
void llist_destroy(LLIST* ptr);

#endif