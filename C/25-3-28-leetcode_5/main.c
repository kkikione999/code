#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 辅助函数：从中心点向外扩展，返回最长回文子串的起始位置和长度
void expandAroundCenter(const char *s, int left, int right, int *start, int *max_len) {
    int n = strlen(s);
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    //离开while前多做了一次left++,right--
    
    // 更新最长回文子串信息
    if (right - left - 1 > *max_len) {
        *start = left + 1;
        *max_len = right - left - 1;
    }
}

char *longestPalindrome(char *s) {
    int n = strlen(s);
    if (n < 2) {
        return s; // 如果字符串长度为 1 或 0，直接返回原字符串
    }

    int start = 0, max_len = 0;

    for (int i = 0; i < n; i++) {
        // 以单个字符为中心（奇数长度回文）
        expandAroundCenter(s, i, i, &start, &max_len);
        // 以两个相邻字符为中心（偶数长度回文）
        expandAroundCenter(s, i, i + 1, &start, &max_len);
    }

    // 分配内存并复制结果
    char *result = (char *)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0'; // 添加字符串结束符
    return result;
}

// 测试代码
int main() {
    char s1[] = "babad";
    char s2[] = "cbbd";

    printf("Longest Palindromic Substring of '%s' is: '%s'\n", s1, longestPalindrome(s1));
    printf("Longest Palindromic Substring of '%s' is: '%s'\n", s2, longestPalindrome(s2));

    return 0;
}