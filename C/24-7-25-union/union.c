#include <stdio.h> 
/*union*/
//union的结构与struct一样
//每个union里面只分配一块可自定义的空间
//所有的成员均可以共享这一片空间
typedef union union_data
{
    int i;                  //分配了4字节的空间
    char ch[sizeof(int)];   
}CHI;
//写入int i = 0x 00 00 04 D2;   4字节的空间内容 00 00 04 D2
//再写入ch[3]=03, ch[4]=04;     4字节的空间内容 04 03 04 D2  

/*union作用*/
//比如说我要查看一个int里面的数据是怎么样的，我可以通过1字节的char查看

int main(void)
{
    CHI chi; // 1234->0x 00 00 04 D2
    chi.i = 1234;
    int cnt;
    for(cnt = 0; cnt<sizeof(int); cnt++)
    {
        printf("%02hhX", chi.ch[cnt]);
    }
    printf("\n");
}
