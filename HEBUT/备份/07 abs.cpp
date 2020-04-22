//7.输入一组数据，按绝对值排序
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int x, temp;
    unsigned int i, j;
    vector<int> v;
    cout << "请输入数组（空格隔开，回车结束）：";
    while (cin >> x)
    {
        v.push_back(x);
        if (getchar() == '\n')
            break;
    }
    for (i = 0; i < v.size() - 1; i++)
        for (j = 0; j < v.size() - i - 1; j++)
            if (abs(v[j]) < abs(v[j + 1]))
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
    for (i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
