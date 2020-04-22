/***********************************************
 * 问题：
 * 参加复试的有n个人，每个人都有qq号，如果两个人互
 * 为qq好友，那么两个人是直接认识，如果通过qq好友可
 * 以认识另一个人，则两个人是间接认识，写出一个算法，
 * 求出复试所有人的直接认识和间接认识。
 * ********************************************/

/***********************************************
 * 解：
 * 首先化为离散数学中 图的问题，用矩阵存储图的信息，
 * 若矩阵中元素为0，表示两个人没有直接认识，元素为1
 * 表示两个人直接认识。
 * 可以利用Warshall算法求解传递闭包的关系(可达)矩阵
 * 统计得到矩阵中非零元素个数，即为 直接认识与间接认
 * 识的人数总和，将该总和减去第一步求出的直接人数的
 * 总数和，便是间接认识的人的总数和。
 * ********************************************/
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
#define N 5

//输出矩阵
void PrintMatrix(int matrix[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//矩阵非零项个数和
size_t SumMatrix(int matrix[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] != 0)
                count++;
        }
    }
    return count;
}

//输入矩阵
int GetMatrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >>matrix[i][j];
        }
    }
}

//沃舍尔算法
void warshall(int a[][N])
{
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (a[j][i])
            {
                for (k = 0; k < N; k++)
                {
                    a[j][k] = a[j][k] | a[i][k];
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != 0)
                a[i][j] = 1;
        }
    }
}

int main()
{
    int Adj[N][N] = {0};
    int temp = 0;
    cout << "请输入矩阵(" << N << "*" << N << ")" << endl;
    GetMatrix(Adj);
    cout << "********邻接矩阵********" << endl;
    PrintMatrix(Adj);
    temp = SumMatrix(Adj);

    cout << "从而得出直接认识的人数：" << temp << endl
         << endl;
    cout << "*******沃舍尔算法*******" << endl;
    warshall(Adj);
    cout << "********可达矩阵********" << endl;
    PrintMatrix(Adj);

    cout << "从而得出间接认识的人数：" << SumMatrix(Adj) - temp << endl;
    return 0;
}
