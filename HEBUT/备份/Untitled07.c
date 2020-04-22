#include <stdio.h>
int main()
{
     int a[10]; //定义数组
     int i;

     for (i = 0; i < 10; i++)
          scanf("%d", &a[i]); //输入

     for (i = 0; i < 10; i++)
          printf("%d ", a[i]); //原样输出。
     return 0;
}