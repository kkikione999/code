#include<stdio.h>
/*指针的使用场景*/
/*使用场景一：多个返回值*/
/*使用场景二：返回函数的状态*/
void Swap(int* pa, int* pb);
int divide(int a, int b, float* result);
int main(void)
{
    int a = 5 , b = 3;
    float result = 0.0;
    Swap(&a, &b);
    if (divide(a, b, &result)) printf("result = %.2f", result);/*函数返回正确的值才能执行printf*/


}
/*使用场景一：多个返回值*/
void Swap(int* pa, int* pb)     
{
    int i = *pa;
    *pa = *pb;
    *pb = i;
}

/*使用场景二：返回异常状态*/
int divide(int a, int b, float* result)
{
    int ret = 1;/*ret的值定义状态*/
    if (b == 0) ret ==0;
    else
    {
        *result = a*1.0/b;
    }
    return ret;
}


//int* const p:说明指针指向的地方不能被修改
/*举例*/
// int value = 10;
// int *const p = &value;
// *p = 20; // 正确：可以修改 p 指向的值
// p++; // 错误：试图改变常量指针的值

//int const* p/ const int* p：说明p指向方向的值不能被修改；
/*举例*/
// int value = 10;
// int const* p = &value;
// *p = 20; // 错误：试图修改常量值
// p++; // 正确：可以改变指针 p 的值

/* *p++ :++优先级高于*，先做++，再做* */
/*NULL代表虚拟地址中的0地址*/

/*void* 指针*/
/*把p看成void类型的指针*/
// int* p = &i;
// void* q = (void*)p;


