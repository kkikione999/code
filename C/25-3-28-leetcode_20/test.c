#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


// 乘法函数，将两个字符串形式的非负整数相乘，并返回结果字符串
char* multiply(char* num1, char* num2) {
    if(num1[0] == '0' || num2[0] == '0')
        return "0";
    
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int resultSize = len1 + len2;
    int * resultArray = calloc(resultSize, sizeof(int));
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2;
            int pos1 = i + j;       // 存储进位的位置
            int pos2 = i + j + 1;     // 存储当前位的结果
            
            int sum = product + resultArray[pos2];//乘积加上当前位的进位结果
            resultArray[pos2] = sum % 10;
            resultArray[pos1] += sum / 10;
        }
    }
    char* resultStr = (char*)malloc((resultSize + 1) * sizeof(char));
    int len_index=0;
    for(len_index = 0; resultArray[len_index] == 0; len_index++);
    int i;
    // while (len_index < resultSize && resultArray[len_index] == 0)
    // {
    //     len_index++;
    // }
    for(i = 0; len_index<resultSize ;i ++)
    {
        resultStr[i] = resultArray[len_index++]+'0';

    }
    resultStr[i] = '\0';
    free(resultArray);
    return resultStr;

}

int main() {
    // 示例测试
    char num1[] = "123";
    char num2[] = "456";
    char* product = multiply(num1, num2);
    printf("输入: num1 = \"%s\", num2 = \"%s\"\n输出: \"%s\"\n", num1, num2, product);
    free(product);
    return 0;
    // int a = trans("003854");
    // printf("%d\n", a);
    exit(0);
}
