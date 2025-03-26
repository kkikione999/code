#ifndef SQSTACK_H__
#define SQSTACK_H__

#define datatype int
#define MAXSIZE 5

typedef struct node_st
{  
    datatype data[MAXSIZE];
    int top;
    
}sqstack;

sqstack *st_create(void);

int st_isempty(sqstack *st);

void st_destory(sqstack *st);

int st_push(sqstack *st , datatype *data);

void st_travel(sqstack *st);

int st_pop(sqstack* st, datatype* data);

#endif
