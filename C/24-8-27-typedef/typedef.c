

/*
*方法一
*/
typedef int* IntPtr;
IntPtr ptr;  // 相当于 int* ptr;


/*
*方式二
*/
typedef struct {
    int x;
    int y;
} Point;
Point p1;  // 声明一个 Point 类型的变量

/*
*方式三
*/
typedef enum {
    RED,
    GREEN,
    BLUE
} Color;
Color color = GREEN;  // 声明一个 Color 类型的变量
