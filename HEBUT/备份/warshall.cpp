#include <stdio.h>
#define N 3    //宏定义
int get_matrix(int a[N][N])
{
    int i = 0,j = 0;
    for (i = 0;i < N;i++)
    {
        for (j = 0;j < N;j++)
         {
            scanf("%d",&a[i][j]);
            if (a[i][j] != 0 && a[i][j] != 1)
                return 1;
         }
    }
    return 0;
}
int output_matrix(int a[N][N])
{
    int i = 0,j = 0;
    for (i = 0;i < N;i++) {
        for (j = 0;j < N;j++) {
            printf("%d  ",a[i][j]);
        }
        putchar('\n');
    }
}
int warshall(int a[][N])
{
    //(1)i＝1；
    //(2)对所有j如果a[j，i]＝1，则对k＝0，1，…，n-1，a[j，k]＝a[j，k]∨a[i，k]；
    //(3)i加1；
    //(4)如果i<n，则转到步骤2，否则停止
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0;i < N;i++)
    {
        for (j = 0;j < N;j++)
        {
            if (a[j][i])
            {
                for (k = 0;k < N;k++)
                {
                    a[j][k] = a[j][k] | a[i][k];//逻辑加
                }
            }
        }
    }
}
int main()
{
    int a[N][N] = {0};
    printf("please input a matrix with %d * %d:\n",N,N);
    if (get_matrix(a))
     {  printf("Get matrix error!Only 0 or 1 in matrix!\n");
        return 1; //错误返回主函数，返回值为1；
     }
    warshall(a);
    output_matrix(a);

    return 0;//正常返回主函数，返回值为0；
}

