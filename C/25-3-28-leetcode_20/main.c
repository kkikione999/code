#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//传入的是左括号
char block_pair(char b)
{
    if(b == '{')
    {
        return '}';
    }
    else if(b == '[')
    {
        return ']';
    }
    else if(b == '(')
    {
        return ')';
    }
    return '\0';

}
while (len_index < resultSize && resultArray[len_index] == 0)
    {
        len_index++;
    }
    
bool isValid(char* s) {
    
    int n = strlen(s);
    if(n%2 != 0)
        return false;
    int top = 0;
    char temp;
    char* stack = malloc(n*sizeof(char));
    
    for(int i = 0; i<n; i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            stack[top++] = s[i];
        }
        else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if(top == 0) {
                free(stack);
                return false;
            }
            temp = stack[--top];
            if (block_pair(temp) != s[i])
            {
                free(stack);
                return false;
            }
        }
    }
    return true;

}

