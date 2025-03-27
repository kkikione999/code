#include <stdio.h>

// 希尔排序函数
void shellSort(int arr[], int n)
{
    // 初始增量为数组长度的一半，逐步减小增量
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // 对每个子序列进行插入排序
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j;
            // 插入排序的核心逻辑
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)  //当gap == 1的时候
                                                                    //就变成了插入排序
            {
                arr[j] = arr[j - gap];
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
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("排序后的数组: \n");
    printArray(arr, n);

    return 0;
}