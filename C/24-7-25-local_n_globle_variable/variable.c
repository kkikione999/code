#include <stdio.h>
/*全局变量*/
//全局变量作用在main函数之前，定义全局变量时：int i = func();这种操作时不允许的
//定义全局变量时，全局变量不能做左值如int i = 3; int b = i;不允许

/*静态本地变量*/
//相当于全局变量，存储的地方与全局变量存储的地方为同一片连续的空间
//作用域与全局变量不同

//在多线程的程序中：少用全局变量
//同时写入和写出会出错
//程序返回值不能是本地变量