#include <stdio.h>
#include <stdlib.h>
const int BLOCK_SIZE = 20;

typedef struct 
{
    int* array;
    int size;
}Array;

Array array_creat(int init_size);
void array_free(Array* a);
int array_size(const Array a);
int* array_at(Array* a, int index);
void array_inflate(Array* a, int more_size);

int main(void)
{
    Array a = array_creat(100);
    printf("array_size:%d\n", array_size(a));
    *array_at(&a,0) = 10;
    printf("a[0] = %d", *array_at(&a,0));
    int number = 0;
    int cnt = 0;
    while (number != -1)
    {
        scanf("%d", &number);
            if (number!=-1)
            {
                *array_at(&a, cnt++) = number;
            }
            
    }
    array_free(&a);
    
}

Array array_creat(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
    return a;
}

void array_free(Array* a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;

}
/*封装的好处*/
//避免在调用的过程中对原始数据造成修改
//有利于后续的维护
int array_size(const Array a)
{
    return a.size;
}

//返回值为指针的好处，可以通过返回值对a进行修改
int* array_at(Array* a, int index)
{
    if ( index >= a->size )
    {
        array_inflate(a, (index/BLOCK_SIZE + 1)*BLOCK_SIZE-a->size);
    }
    return &(a->array[index]);
}

void array_inflate(Array* a, int more_size)
{
    int* p = (int*)malloc(sizeof(int)*(a->size + more_size));
    int i;
    for(i = 0; i< a->size; i++)
    {
        p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size = more_size;
}