#include <stdlib.h>
#include <stdio.h>

#define min(a,b) (a)>(b) ? (b) : (a)
//超时
//int minSubArrayLen(int target, int* nums, int numsSize)
//{
//    int head = 0, tail = 0;
//    int sum;
//    int size = 999;
//    for(int i = 0; i<numsSize; i++)
//    {
//        tail = head;
//        for(sum = 0; head<numsSize; head++)
//        {
//            sum += nums[head];
//            if(sum>=target)
//            {
//                size = min(size, head-tail+1);
//                break;
//            }
//        }
//
//        head = tail+1;
//        if(size == 1)
//            return size;
//    }
//    if(size == 999)
//        return 0;
//    return size;
//}










int main()
{
    int arr[] = {1,1,1,1,1,1,1,1};
    int res = minSubArrayLen(11,arr, sizeof(arr)/sizeof(arr[0]));
    printf("mini len is : %d\n", res);

    exit(0);

}