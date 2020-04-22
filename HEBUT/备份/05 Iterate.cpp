//Example：给定字符串“ABCDBGAC”，打印“A B C”
#include <iostream>
#include <string>
using namespace std;

struct ASCII
{
    char a;
    size_t count;
};

void PrintIterateChar(const string a)
{
    string s = a;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '#') //判断i指针的指向是否为输出过的字符
            continue;
        int m = 1; //判断j指针的指向是否为输出过的字符
        for (int j = i + 1; j <= s.size() - 1; j++)
        {
            if (s[i] == s[j])
            {
                if (m == 1)
                    cout << s[i] << " ";
                s[j] = '#'; //对输出过的字符做标记
                m = 0;      //对输出过的字符做标记
            }
        }
    }
}

void PrintIterateChar2(const string a)
{
    ASCII b[128];
    for (int i = 0; i <= 128; i++)
    {
        b[i].a = 0; //ASCII 0 = NULL
        b[i].count = 0;
    }
    for (int i = 0; a[i] != '\0'; i++)
    {
        b[a[i]].a = a[i];
        b[a[i]].count++;
    }
    for (int i = 0; i < 128; i++)
    {
        if (b[i].count > 1)
            cout << b[i].a << " ";
    }
    cout << endl;
}
int main()
{
    string a;
    cin >> a;
    PrintIterateChar(a);
    cout << endl;
    PrintIterateChar2(a);
    cout << endl
         << a;
    return 0;
}
