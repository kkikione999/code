#include <stdio.h>
/*枚举enum*/
//枚举实际上就是int类型的量
//若未定义第一个枚举量，则数据从0开始依次递增
//通常定义最后一个量为number of enum


enum color { red, bule, green, grey, NUMcoler};

//枚举配合typedef使用
//离散的枚举定义
typedef enum apple
{
    green_apple = 1, bule_apple, purple_apple = 4
}_apple;

void func(enum color z)     //枚举作为形参传入函数的方法
{
    printf("%d\n", z);
}

int main(void)
{
    enum color e = NUMcoler;
    func(e);

    _apple a1 = green_apple;
    _apple a2 = bule_apple;
    _apple a3 = purple_apple;
    printf("green_apple = %d\n", green_apple);
    printf("a1 = %d\n", a1);
    printf("a2 = %d\n", a2);
    printf("a3 = %d\n", a3);
    




}