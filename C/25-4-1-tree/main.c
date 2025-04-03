#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

void insertsort(int* arr, int size)
{
    for(int i = 1; i<size; i++)
    {
        int temp = arr[i];
        int j;
        for(j = i; arr[j-1]>temp && j>0; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

void shellsort(int* arr, int size)
{
    for(int gap = size/2; gap>0; gap/=2)
    {
        for(int i = gap; i<size; i++)
        {
            int temp = arr[i];
            int j;
            for(j = i; j>=gap && arr[j-gap] > temp; j-=gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

int main ()
{
    char* str = "ABCDEFGHYJK";

    tree_st* ptr = tree_create(str[0]);

    for (int i = 0; i < strlen(str); i++)
    {
        tree_insert(ptr, str[i]);
    }

    tree_print(ptr);
    
    tree_destory(ptr);


    printf("\n");
    return 0;

}