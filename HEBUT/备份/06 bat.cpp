#include <iostream>

int main()
{
    int n, a = 0, b = 0;
    std::cout << "How many bats are you encountering? ";
    std::cin >> n;
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
    std::cout << "Destroy all bats requires A " << a << " times and B " << b << " times";
    return 0;
}
