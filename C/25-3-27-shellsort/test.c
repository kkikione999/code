#include <stdio.h>

// 希尔排序函数
void shellSort(int arr[], int size)
{
    if(size <= 0)
    {
        return;
    }
    //以原始数组的一半长度为一个gap
    for (int gap = size / 2; gap > 0; gap /= 2) 
    {
        //从arr[i]往后的元素和arr[i-gap]的元素开始比较
        //并且每一轮i++自增
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            if(gap > 1)
            {
                if(arr[i] < arr[i-gap])
                {
                    arr[i] = arr[i-gap];
                    arr[i-gap] = temp;
                }
            }
            //当gap==1的时候就可以开始插入排序
            else if(gap == 1)
            {
                for(int j = 1; j < size; j++)
                {
                    int q = j-1;
                    temp = arr[j];
                    while (temp < arr[q] && q >= 0)//注意要用temp和arr[q]作比较 不要用arr[j]和arr[q]作比较，并且要防止数组越界
                    {
                        arr[j] = arr[q];
                        q--;
                    }
                    arr[q+1] = temp;
                }
            }
            
        }
    }
}

//优化版本
void shellsort(int arr[], int size)
{
    for(int gap = size/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            for(j = i; j>=gap && arr[j-gap] > temp;j-=gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 主函数
int main() {
    int arr[] = {5,23,21,3,6,7,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: \n");
    printArray(arr, n);

    insertsort(arr, n);

    printf("排序后的数组: \n");
    printArray(arr, n);

    return 0;
}