#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void choosesort(int* arr, int size)
{
    int min_index, tmp;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i; // 假设当前起点是最小值
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j; // 找到更小的值，更新索引
            }
        }
        // 如果找到的最小值索引不是当前起点，则交换
        if (min_index != i)
        {
            tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
}

int main()
{
    int arr[] = {3,2,1};
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("arr[%d] = %d  ", i, arr[i]);
    }
    printf("\n");
    choosesort(arr,  sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("arr[%d] = %d  ", i, arr[i]);
    }
    printf("\n");
    exit(0);
}

