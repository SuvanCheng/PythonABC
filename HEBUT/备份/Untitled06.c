#include <stdio.h>
void main()
{
    int n = 65, a = 0, b = 0;
    while (n)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            a++;
        }
        else
        {
            n = n - 1;
            b++;
        }
    }
    printf("A:%d B:%d", a, b); // 65 64 32 16 8 4 2 1
}
