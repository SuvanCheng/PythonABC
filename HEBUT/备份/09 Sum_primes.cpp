//9.给定范围，如[10,2003]，计算该范围内所有素数的和
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

size_t Sumprimes(size_t Start, size_t End)
{
    bool flag = 1;
    size_t sum = 0;
    size_t h = 0;
    cout << "......... prime table(" << Start << "->" << End << ")........." << endl;
    for (int i = Start; i <= End; i++)
    {
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            std::cout << setw(4) << i;
            sum += i;
            h++;
            if (h % 10 == 0)
            {
                std::cout << std::endl;
            }
        }
        flag = 1;
    }
    std::cout << std::endl;
    return sum;
}

int main()
{
    int Start, End, sum = 0;
    do
    {
        cout << "Input START and END:";
        cin >> Start >> End;
    } while (!(Start > 0 && Start < End));
    sum = Sumprimes(Start, End);
    cout << "The sum of all primes is " << sum << endl;
    return 0;
}
