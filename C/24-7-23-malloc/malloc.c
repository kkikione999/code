#include <stdio.h>
#include <stdlib.h>
/*malloc定义*/
2
/*malloc常见问题*/
// 使用了malloc没有free
// free过了再free
// 使用malloc后指针的地址变更了无法free

/*解决办法*/
// 定义指针时赋值为NULL
int main(void)
{
    // int* p = NULL;
    // int i = 8;
    // p = (int*)malloc(1024*1024*1024);
    // p[0] = 1;
    // p[1] = 2;
    // printf("p[1] = %d\n", p[1]);
    // free(p);

    void *p = NULL; //配合free使用
    int cnt = 0;
    /*malloc()使用方法*/
    //在使用malloc*(p)后，指针不能指向别的敌方，否者无法释放内存（无法free）

    /*malloc()返回值*/
    //1. 申请到的首地址
    //2. 在申请不到内存的时候返回的是NULL（地址0）

    /*free(p) 如果 p = NULL, 那么free函数不做动作，如果p != NULL ：释放内存*/
    //一般定义指针的时候把指针初始化NULL
    //如果在使用free(p)之前没有对p进行过malloc(p)操作，系统也不会报错


    /*NULL在不同的编译器下地址可能不同，大多数都是地址0*/

    while ((p = malloc(100 * 1024 * 1024)) != NULL) 
    {
        cnt++;
    }
    free(p);
    printf("%d00MB\n", cnt);
    printf("NULL = %p", NULL);
    
}