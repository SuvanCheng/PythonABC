#include <stdio.h>
#include <string.h>
void main()
{
    char s[100]; // 存放输入的字符串
    int i, j, n;
    printf("输入字符串：");
    gets(s);
    n = strlen(s);
    for (i = 0, j = n - 1; i < j; i++, j--)    //当 i < j 遍历结束
        if (s[i] != s[j])    //首尾比较，相等继续
            break;
    if (i >= j)
        printf("是回文串\n");
    else
        printf("不是回文串\n");
}
