#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0
//暴力解法：超时
int largestRectangleArea(int* heights, int heightsSize) {
    int* curr = heights;
    int maxarea = 0;
    int localmaxarea = 0;
    int localmaxlen;
    for(int i = 0; i<heightsSize; i++)
    {
        localmaxlen = curr[i];
        for (int j = i; j < heightsSize ; j++)
        {
            int area;
            if(localmaxlen>curr[j])
                localmaxlen = curr[j];
            area = localmaxlen * (j-i+1);
            if(area>localmaxarea)
                localmaxarea = area;
        }
        if(localmaxarea>maxarea)
            maxarea = localmaxarea;
    }
    return maxarea;
}
#endif

#define max(a,b) ((a) > (b) ? (a) : (b))

//单调栈
int largestRectangleArea(int* const heights, int heightsSize) {
    // 申请新的数组 p，左右各补一个 0
    int *p = (int*)malloc((heightsSize + 2) * sizeof(int));
    p[0] = 0;
    p[heightsSize + 1] = 0;
    memcpy(p + 1, heights, heightsSize * sizeof(int));

    // 准备一个栈，下标从 0 开始，初始只放 p[0] 即高度=0
    int *stack = (int*)malloc((heightsSize + 2) * sizeof(int));
    int top = 0;
    stack[0] = 0;

    int area = 0;

    // 注意循环到 heightsSize+1
    for (int i = 1; i < heightsSize + 2; i++) {
        // 当出现当前柱子高度 p[i] 小于 栈顶柱子高度 p[stack[top]] 时，需要弹栈
        while (p[i] < p[stack[top]]) {
            int hIndex = stack[top--];  // 弹出栈顶
            int h = p[hIndex];          // 这是被弹出柱子的高度
            // 宽度 = 当前 i - 栈顶新的 top - 1
            int width = i - stack[top] - 1;
            area = max(area, h * width);
        }
        // 把当前下标压栈
        stack[++top] = i;
    }

    free(stack);
    free(p);
    return area;
}

int main() {
    int heights[] = {2,1,2};
    int size = sizeof(heights) / sizeof(heights[0]);
    int maxArea = largestRectangleArea(heights, size);
    printf("max area: %d\n", maxArea);
    return 0;
}