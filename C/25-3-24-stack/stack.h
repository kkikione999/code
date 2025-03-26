#ifndef STACK_H__
#define STACK_H__
#include "llist.h"

typedef LLIST STACK;

STACK *stack_create(int);

int stack_push(STACK* ptr,void* data);

void stack_destroy(STACK *ptr);

static int always_match(const void* p1,const void* p2);

int stack_pop(STACK *ptr, void *data);

#endif
