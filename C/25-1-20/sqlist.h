#ifndef SQLIST_H__
#define SQLIST_H__

#define DATASIZE 1024
typedef int datatype;
typedef struct node_st
{
    datatype data[DATASIZE];
    int last;
}sqlist;


sqlist* sqlist_create();
void sqlist_create1(sqlist **);
int sqlist_insert(sqlist *me,int i, datatype *data);

int sqlist_destroy(sqlist *);
// int sqlist_find(sqlist *, datatype i);
// int sqlist_setempty(sqlist *);
// int sqlist_getnum(sqlist *);
// int sqlist_union(sqlist *);
// int sqlist_delete(sqlist *, int i);
 void sqlist_display(sqlist *me);

#endif