#include<stdio.h>
#include<math.h>
int main()
{
    int start, end, i, k, m, n = 0, flag=1, h=0;
    do
    {
        printf("Input START and END:");
        scanf("%d%d", &start, &end);
    }while(!(start>0 && start<end));
    printf("......... prime table(%d-%d).........\n", start, end);
    for(m=start; m<=end; m++)
    {
        k=sqrt(m);
        for(i=2; i<=k; i++)
            if(m%i==0)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            printf("%-4d",m);
            n += m;
            h++;
            if(h%10==0)
                printf("\n");
        }
        flag=1;
    }
    printf("\nThe total is %d", h);
    printf("\nThe sum of all primes is %d", n);

    return 0;
}
