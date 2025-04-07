#include<stdio.h>
#define SIZE 6              /*创建数组一般数组长度要进行宏定义，便于修改*/
int Sum(int* ar, int size); /*传入数组参数可以int a[]/int* ar 传入数组通常加上数组长度*/
                            /*此时形参int a[]实际上就是一个指针，不是数组，因此在函数中无法得出数组的长度*/
#if 0
int main()
{
    int a1[SIZE] = { 0,[4] = 5,};//a1[4] = 5
    int sum = 0;
    sum = Sum(a1,SIZE);
    //printf("Sum = %d", sum);

    int a2[] = {2,3,4};
    /*等价于*/
    // int* const a2 = 0x61FDF4;
    // a2[0] = 2;
    // a2[1] = 3;
    // a2[2] = 4;
    printf("%p\n",a2);
    printf("%d", a2[1]);

}
#endif

int main()
{
    int a[3][4];
    for(int i = 0; i < 3; i++)
    {
        printf("i = %d\n", i);
        for (int j = 0; j < 4; j++)
        {
            a[i][j] = i + j;
            printf("a[%d][%d] = %x\t", i, j, *a[i]+j); 
        }
        printf("\n"); 
    }
    return 0;
}


int Sum(int* ar, int size)
{
    int i;
    int for(i = 0; i<size; i++)
    {
        Sum += ar[i];
    }
    return Sum;
}
/*int a[] == int* const a */
