#include <stdlib.h>
#include <stdio.h>


void insertsort(int *arr, int size)
{
    int j, key;
    for(int i = 1; i<size; i++)
    {
        j = i-1;
        key = arr[i];
        //在arr[i]之前
        //只要比arr[i]大就往后挪一个位置
        while (j<size && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        //到循环结束之间进行了一次i--
        arr[j+1] = key;
    }
}


int main()
{
    int arr[] = {5,2,8,4,6};
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("arr[%d] = %d  ", i, arr[i]);
    }
    printf("\n");
    insertsort(arr,  sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("arr[%d] = %d  ", i, arr[i]);
    }
    printf("\n");
    exit(0);
}

