#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubblesort(int* arr, int size)
{
    int n = size;
    int temp;
    bool swapped;
    while (n)
    {
        swapped = false;
        for (int i = 0; i < n - 1; i++) // 内层循环范围逐渐缩小
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
        n--; // 每轮结束后，减少内层循环的范围
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
    bubblesort(arr,  sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("arr[%d] = %d  ", i, arr[i]);
    }
    printf("\n");
    exit(0);
}

