#include <stdio.h>

int main()
{
    double thred;
    double sum=0;
    double last=1.0;
    int i=0;
    scanf("%lf",&thred);
    while(last > thred)
    {
    	sum += 2*last;
    	i++;
    	last = last*i/(2*i+1);
    }
    sum += 2*last;
	printf("%.6lf\n",sum);
    return 0;
}
