/***********************************************
 * ���⣺
 * �μӸ��Ե���n���ˣ�ÿ���˶���qq�ţ���������˻�
 * Ϊqq���ѣ���ô��������ֱ����ʶ�����ͨ��qq���ѿ�
 * ����ʶ��һ���ˣ����������Ǽ����ʶ��д��һ���㷨��
 * ������������˵�ֱ����ʶ�ͼ����ʶ��
 * ********************************************/

/***********************************************
 * �⣺
 * ���Ȼ�Ϊ��ɢ��ѧ�� ͼ�����⣬�þ���洢ͼ����Ϣ��
 * ��������Ԫ��Ϊ0����ʾ������û��ֱ����ʶ��Ԫ��Ϊ1
 * ��ʾ������ֱ����ʶ��
 * ��������Warshall�㷨��⴫�ݱհ��Ĺ�ϵ(�ɴ�)����
 * ͳ�Ƶõ������з���Ԫ�ظ�������Ϊ ֱ����ʶ������
 * ʶ�������ܺͣ������ܺͼ�ȥ��һ�������ֱ��������
 * �����ͣ����Ǽ����ʶ���˵������͡�
 * ********************************************/
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
#define N 5

//�������
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

//��������������
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

//�������
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

//������㷨
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
    cout << "���������(" << N << "*" << N << ")" << endl;
    GetMatrix(Adj);
    cout << "********�ڽӾ���********" << endl;
    PrintMatrix(Adj);
    temp = SumMatrix(Adj);

    cout << "�Ӷ��ó�ֱ����ʶ��������" << temp << endl
         << endl;
    cout << "*******������㷨*******" << endl;
    warshall(Adj);
    cout << "********�ɴ����********" << endl;
    PrintMatrix(Adj);

    cout << "�Ӷ��ó������ʶ��������" << SumMatrix(Adj) - temp << endl;
    return 0;
}
