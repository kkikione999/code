#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 回溯函数，参数含义如下：
// s：输入的数字字符串
// start：当前切分的起始位置
// part：已经切分出的段数（0~4）
// path：当前构造的 IP 地址（包括'.'）
// pathIndex：当前 path 中的写入位置
// result：存放结果的字符串数组指针（动态扩容）
// returnSize：结果数组中元素个数
// capacity：结果数组的当前容量
// backtrack(s, 0, 0, path, 0, &result, returnSize, &capacity);
void backtrack(char *s, int start, int part, char *path, int pathIndex,
               char ***result, int *returnSize, int *capacity) {
    // 当已经切分为4段且刚好用完所有字符时，得到一个有效的 IP 地址
    if (part == 4 && s[start] == '\0') {
        path[pathIndex - 1] = '\0';  // 去掉最后一个多余的'.'
        // 将当前构造的 IP 地址复制到结果数组中
        (*result)[*returnSize] = strdup(path);
        (*returnSize)++;
        // 动态扩容
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char *));
        }
        return;
    }
    // 如果已经切分为4段但还未用完字符，或者字符用完但段数不足，则剪枝
    if (part == 4 || s[start] == '\0')
        return;
    
    int len = strlen(s);
    // 每一段的长度最多为3
    for (int i = 1; i <= 3; i++) {
        // 如果剩余字符不足i个，则退出循环
        if (start + i > len)
            break;
        char segment[4] = {0};  // 最多存放3位数字，加上结尾'\0'
        strncpy(segment, s + start, i);
        segment[i] = '\0';
        // 检查是否有前导0：如果段长度大于1且首字符为'0'则非法
        if (i > 1 && segment[0] == '0')
            continue;
        // 转换为整数并检查范围
        int value = atoi(segment);
        if (value > 255)
            continue;
        
        // 将该段及'.'追加到 path 中
        int newIndex = pathIndex;
        strcpy(path + newIndex, segment);
        newIndex += i;
        path[newIndex++] = '.';
        // 递归处理剩余字符串
        backtrack(s, start + i, part + 1, path, newIndex, result, returnSize, capacity);
    }
}

// 主函数，返回所有可能的有效 IP 地址，并通过 returnSize 返回个数
char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;
    int capacity = 16;  // 初始容量
    char **result = malloc(capacity * sizeof(char *));
    int len = strlen(s);
    // 如果字符串长度不在 [4,12] 内，必然无法构造有效 IP 地址
    if (len < 4 || len > 12)
        return result;
    // path 数组最大长度为 12（数字）+ 4（点） = 16（包括结尾'\0'）
    char path[16];
    backtrack(s, 0, 0, path, 0, &result, returnSize, &capacity);
    return result;
}

int main() {
    char s[25];
    printf("请输入只包含数字的字符串: ");
    scanf("%s", s);
    int returnSize;
    char **ips = restoreIpAddresses(s, &returnSize);
    printf("共找到 %d 个有效 IP 地址：\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", ips[i]);
        free(ips[i]);
    }
    free(ips);
    return 0;
}
