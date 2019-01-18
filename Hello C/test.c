#include <stdio.h>

long factorial(int);

int main()
{
    int n;
    long f;

    printf("Enter an integer to find its factorial\n");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial of negative integers isn't defined.\n");
    else
    {
        f = factorial(n);
        printf("%d! = %ld\n", n, f);
    }
    return 0;
}

long factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    a = 10;
    b = a++;
    c = ++a;
    d = 10 * a++;
    printf("b, c, d: %d, %d, %d", b, c, d);
    return 0;
}

#include <stdio.h>
// 说明：以下代码是把一个字符串倒序，如“abcd”倒序后变为“dcba”
int main()
{
    char *src = "hello,world";
    int len = strlen(src);
    char *dest = (char *)malloc(len + 1); //要为分配一个空间
    char *d = dest;
    char *s = &src[len - 1]; //指向最后一个字符
    while (len-- != 0)
        *d++ = *s--;
    *d = 0; //尾部要加’\0’
    printf("%s", dest);
    free(dest);  // 使用完，应当释放空间，以免造成内存汇泄露
    dest = NULL; //防止产生野指针return 0;

    return 0;
}

int main()
{
    char str[] = "hello,world";
    int len = strlen(str);
    char t;
    for (int i = 0; i < len / 2; i++)
    {
        t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
    printf("%s", str);
    return 0;
}

#include <string.h>
#include <stdio.h>
typedef int *PINNT;
#define PP int *

int funcA(int a, int b);
int funcB(int *a, int *b);
int main(int argc, char *argv[])
{
    int (*func)(int, int);
    //func = &funcA;
    func = funcA;
    //两种赋值给函数指针的方法都可以
    printf("%d", func(1, 10));
    //printf("%d",(*func)(1,10));
    //两种调用函数指针的方法都可以
    //两种赋值方法和两种调用方法可以任选一种组合
}

int funcA(int a, int b)
{
    return a + b;
}

int funcB(int *a, int *b)
{
    (*a) = (*a) + (*b);
    return 1;
}

int inc(int a)
{
    　return (++a);
}
int multi(int *a, int *b, int *c)
{
    　return (*c = *a * *b);
}
typedef int(FUNC1)(int in);
typedef int(FUNC2)(int *, int *, int *);

void show(FUNC2 fun, int arg1, int *arg2)
{
    　FUNC1 *p = &inc;
    　int temp = p(arg1);
    　fun(&temp, &arg1, arg2);
    　printf("%d\n", *arg2);
}

main()
{
    　int a;
    　show(multi, 10, &a);
    　return 0;
}