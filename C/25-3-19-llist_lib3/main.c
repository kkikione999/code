#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#define NAME_SIZE 32

struct score_st
{
    char name[NAME_SIZE];
    int id;
    int math;
    int chinese;

};

static int id_cmp(const void *key, const void *reccord)
{
    const int * k = key;
    const struct score_st *r = reccord;
    return (*k - r->id);

}

void print_s(const void *r) {
    const struct score_st *data = (const struct score_st *)r;  // 先转换指针
    if (!data) {
        printf("Error: NULL pointer in print_s()\n");//最好加上这一段
        return;
    }
    printf("%s\t%d\t%d\t%d\n", data->name, data->id, data->chinese, data->math);
}

int main ()
{
    int i = 0;
    int ret;
    LLIST *handler;
    struct score_st temp;
    handler = llist_create(sizeof(struct score_st));
    if(handler == NULL)
        exit(1);
    
    for(i = 0; i<7 ; i++)
    {
        temp.id = i;
        temp.math = rand()%100;
        temp.chinese = rand()%100;
        snprintf(temp.name, NAME_SIZE, "std%d", i);

        ret = handler->insert(handler, &temp, LLIST_BACKWARD);
        if(ret)
            exit(1);
    }
    handler->travel(handler, print_s);

    printf("\n\n");
    int id = 8;
    struct score_st *data;
    data = handler->find(handler, &id, id_cmp);
    if(data == NULL)
        printf("can't find");
    else
        print_s(data);
    llist_destroy(handler);
    return 0;
}

