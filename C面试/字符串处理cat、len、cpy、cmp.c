#include <stdio.h>
#include <assert.h>
#include <string.h>

#define test_numOfstr 0
#define test_findkey  0
#define test_mystring 1

int mystrlen(char *str)
{
    int count = 0;
    while (str[count] != '\0'){
        count++;
    }
    return count;
}



char *mystrcat(char *str1, char *str2)
{
    char *str = str1; //定义字符串指针
    while (*str)      //当str不为“\0”时不断向下移
        str++;
    while (*str2)
        *str++ = *str2++; //将str2复制到str1的末尾
    *str = '\0'; //末尾一定添加“\0”使字符串截止
    return str1;
}

char *mystrcpy(char *dest, const char *src)
{
    assert(dest != NULL && src != NULL);
    char *index = dest; //记录首地址
    while ((*dest++ = *src++)) {} //一个一个复制，直到结尾/0
    return index;
}

int mystrcmp(const char *str1, const char *str2) {
    while (*str1 || *str2) {
        if (*str1 > *str2)
            return 1;
        else if (*str1 < *str2)
            return -1;
        str1++;
        str2++;
    }
    return 0;
}

int mystrcmp2(const char *str1, const char *str2)
{
    //assert( str1 != NULL && str2 != NULL);
    while (*str1 == *str2 && *str1 != '\0')
    {
        str1++;
        str2++;
    }
    if (*str1 > *str2)
        return 1;
    else if (*str1 < *str2)
        return -1;
    else
        return 0;
}

int findkey(const char *str, const char key)
{ //找到一个字母
    int index = -1;
    while (str[++index] != '\0')
    {
        if (str[index] == key)
            return index;
    }
    return -1;
}

int numOfstr(char *str, char *substr)
{
    int num = 0;
    char *s1, *s2;
    while (*str != '\0')
    {
        s1 = str;
        s2 = substr;
        while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))
        {
            s1++;
            s2++;
        }
        if (*s2 == '\0')
        {
            num++;
        }
        str++;
    }
    return num;
}

int main(void)
{

#if test_numOfstr
    char *str = "My name is SuvanCheng, I used name BruceCheng"; //不知道定义字符串用双引号
    char *substr = "Cheng";
    int num;
    num = numOfstr(str, substr);
    printf("%d\n", num); //不知道打印用双引号
#endif

#if test_findkey
    char *str = "I have a dream, Mom and Dad have Honor with me";
    char key = 'H';
    printf("%d\n", findkey(str, key));
#endif

#if test_mystring
    char *src = "Count me, and tell me how long is me?";
    char str1[] = "My name is ";
    char str2[] = "my name is";
    char *str3 = "";
    printf("src lenth %d\n", mystrlen(src));
    printf("%s \n", strcat(str1, str2));
    //printf("%d\n",mystrcmp2(str1,str2));
    //printf("%d\n",mystrcmp(str1,str2));
    //mystrcpy(str3,str1);
    printf("%s\n", src);
#endif

    return 0;
}
