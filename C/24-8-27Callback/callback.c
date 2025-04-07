#include <stdio.h>
/*
*************方式一
***********无参数调用
*/
/*callback_func*/
int callback_func(void)
{
    printf("is callback func\n");
    return 0;

}

/*中间函数*/
//void helper_func(int (*thing)(void))等价
void helper_func(int (*thing)())
{
    thing();
}

/*
***************方式二
************有参数调用
*/

/*callback_func*/
int sub(int a, int b)
{
    return a-b;
}

/*中间函数*/
int helper_func2(int (*thing)(int, int))
{
    return thing(2,3);
}


int main()
{
    helper_func(callback_func);//callback_func是函数地址
    int ret = helper_func2(sub);
    printf("ret = %d", ret);

    return 0;

}

void callback_func(void())

/*
*总结
*回调函数void callback_func(int,int);
*回调函数与普通函数并无差别

*中间函数int helper_func(void (*CALLBACK)(int,int));
* 这个中间函数要求传入的函数（回调函数）的返回值要是void类型，传入的函数（回调函数）的参数是（int， int）两个int类型
*只要符合传入函数要求的都可以作为此中间函数的回调函数
*中间函数的返回值是int类型

*但是中间函数和普通函数不同：区别在于传入的参数是回调函数的地址
*中间函数传入回调函数的地址是回调函数的函数名helper_func(callback_func);（不用加参数）


*定义void callback_func(void(*func_name)(int,int))
*传入
*
*
*
*
**/