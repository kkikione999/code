#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point* p);

int main(int argc, char const *argv[])
{
    struct point y = {0,0};
    getStruct(&y);
    output(y);
    output(*getStruct(&y));
    print(getStruct(&y));
    getStruct(&y)->x = 0;
    *getStruct(&y) = (struct point){1,2};//对结构体指针取内容*：取得是所有成员
}
/*通常传结构体的地址进函数*/
//并且传出结构体的指针
//对结构体指针取内容*：取得是所有成员
struct point* getStruct(struct point *p) //如果传结构体进去做的是值的复制，与传数组进去不同
{
    scanf("%d", &p->x);
    scanf("%d", &p->y);
    printf("%d, %d", p->x, p->y);
    return p;
};

void output(struct point p)
{
    printf("%d, %d", p.x, p.y);
}

void print(const struct point *p)
{
    printf("%d, %d", p->x, p->y);
}
