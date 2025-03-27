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
        while (j>=0 && arr[j]>key)                      //注意j>=0以防数组越界
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void insertSort(int* arr, int size)
{
    int temp, j;
    for (int i = 1; i < size; i++) {
        temp = arr[i];
        for(j = i; temp < arr[j-1] && j >= 1; j--)      //注意j>=1，如果写成j>=0的话
														//数组会越界
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
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

