#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
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
    const struct score_st *data = r;
    if (!data) {
        printf("Error: NULL pointer in print_s()\n");//最好加上这一段
        return;
    }
    printf("%s\t%d\t%d\t%d\n", data->name, data->id, data->chinese, data->math);
}

int main ()
{
    STACK *st;
    struct score_st tmp;
    int ret;
    st = stack_create(sizeof(struct score_st));
    if(st == NULL)
        exit(1);
    
    for(int i = 0; i<7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAME_SIZE, "stu%d", i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;

        if(stack_push(st, &tmp))
        exit(1);
    }

    while (1)
    {
        ret = stack_pop(st, &tmp);
        if (ret == -1)
            break;
        print_s(&tmp);
        
    }
    stack_destroy(st);

    
    
    return 0;
}

