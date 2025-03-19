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

int id_cmp(const void* data, const void * data_struct)
{
    const int * k = data;
    const struct score_st* p = (const struct score_st*)data_struct;
    return (p->id - *k);
}

// void print_s(const void *r)
// {
//     //const struct score_st *data = (const struct score_st *)r;
//     const struct score_st *data = (const struct score_st *)r;  // 先转换指针
//     //printf("%s\t%d\t%d\t%d\n", data->name, data->id, data->chinese, data->math);
//     printf("%s\t%d\t%d\t%d\n", data->name, data->id, data->chinese, data->math);

// }
void print_s(const void *r) {
    const struct score_st *data = (const struct score_st *)r;  // 先转换指针
    if (!data) {
        printf("Error: NULL pointer in print_s()\n");
        return;
    }
    printf("%s\t%d\t%d\t%d\n", data->name, data->id, data->chinese, data->math);
}

int main()
{
    int i;
    int info = 0;
    LLIST *handlar;
    struct score_st temp;
    struct score_st fetch_data;
    handlar = llist_creat(sizeof(struct score_st));
    if (handlar ==NULL)
    {
        exit(0);
    }
    for(i = 0; i<7 ; i++)
    {
        temp.id = i;
        temp.math = rand()%100;
        temp.chinese = rand()%100;
        snprintf(temp.name, NAME_SIZE, "std%d", i);
        llist_insert(handlar, &temp, LLIST_BACKWARD);
    }
    llist_travel(handlar, print_s);
    
    int id = 3;
    struct score_st *ptr = NULL;

    info = llist_delete(handlar, &id,id_cmp);
    if(info != 0)
    {
        printf("no data to have been deleted\n");
    }
    id = 5;
    info = llist_fetch(handlar, &id, id_cmp, &fetch_data);
    print_s(&fetch_data);
    if(info != 0)
    {
        printf("no data to have been fetched\n");
    }

    printf("\n\nbelow is new data\n");
    llist_travel(handlar, print_s);
    
    llist_destory(handlar);
    
    return 0;







}
