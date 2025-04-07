#include <stdio.h>

#define configSTRUCT_DEFINITION1 0  //结构的定义方式1
#define configSTRUCT_DEFINITION2 0  //结构的定义方式2
#define configSTRUCT_DEFINITION3 0  //结构的定义方式3
#define configSTRUCT_POINTER_USE 1  //结构体指针


/*结构的定义方式*/



#if ( configSTRUCT_DEFINITION1 == 1 )
    //结构的定义方式1
    struct  
    {
        /* data */
        int p;
        int i;
        int d;

    }pid1,pid2;
#endif

#if ( configSTRUCT_DEFINITION2 == 1 )
    //结构的定义方式2
    struct PID
    {
        /* data */
        int p;
        int i;
        int d;
    };
#endif

#if ( configSTRUCT_DEFINITION3 == 1 )
    //结构的定义方式3
    typedef struct PID2
    {
        /* data */
        int p;
        int i;
        int d;
    }_PID;
#endif

#if ( configSTRUCT_POINTER_USE == 1 )
    typedef struct PID2
    {
        /* data */
        int p;
        int i;
        int d;
    }_PID;
#endif

int main(void)
{
    // PID1
    // pid1 = {p = 1,i = 2,d = 3};


    // pid2 = pid1;
#if ( configSTRUCT_DEFINITION1 == 1 )
    //结构定义方式1
    {   //struct 里面的成员未赋初始值默认为0
        pid1.p = 1;
        pid1.i = 2;
        // pid1 = {1,2,3};不允许

        pid2 = pid1;    //数组不可以给数组赋值，但是结构可以给结构赋值
        
        printf("pid2.p = %d\n", pid2.p);
        printf("pid2.i = %d\n", pid2.i);
        printf("pid2.d = %d\n", pid2.d);
    }
#endif

#if ( configSTRUCT_DEFINITION2 == 1 )
    //结构定义方式2
    struct PID pidx = {3,4,5};  //结构定义方式1不可以用这种方法赋初始值
    printf("pidx.p = %d\n", pidx.p);
    printf("pidx.i = %d\n", pidx.i);
    printf("pidx.d = %d\n", pidx.d);
#endif

#if ( configSTRUCT_DEFINITION3 == 1 )
    //结构定义方式3
    _PID _pid1 = {.p = 1, .i = 2};//没有赋值的默认赋值为0，".成员 = value"
    printf("_pid1.p = %d\n", _pid1.p);
    printf("_pid1.i = %d\n", _pid1.i);
    printf("_pid1.d = %d\n", _pid1.d);
#endif

#if ( configSTRUCT_POINTER_USE == 1 )
    //结构体指针
    _PID _pid1 = {.p = 1, .i = 2};//没有赋值的默认赋值为0，".成员 = value"
    _PID *Ptr = &_pid1;
    printf ("p = %p\n", Ptr->p);
    printf ("i = %d\n", Ptr->i);
    printf ("d = %d\n", Ptr->d);

#endif
}



