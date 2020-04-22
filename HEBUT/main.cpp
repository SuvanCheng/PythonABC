#include <iostream>
#include "Solution.h"
#include "LinkedList.h"

int main() {
    Solution solution;
/*
    //1.删减字符串中特定的字符
    std::string str;
    size_t n;
    char a1;

    std::cout << "Input a String: ";
    std::cin >> str;
    std::cout << "Input a char: ";
    std::cin >> a1;
    std::cout << "Input a Number: ";
    std::cin >> n;
    solution.substr(str, a1, n);

    //0.二分查找，返回索引
    double array_f[] = { 1.79, 1.80, 1.81, 1.82, 1.83, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.90, 1.91, 1.92 };
    double j;

    std::cout << "Input the search number:";
    std::cin >> j;

    int location = BinarySearch(array_f, sizeof(array_f) / sizeof(array_f[0]), j);
    if (location != -1)
        std::cout << "BinarySearch:" << location + 1 << std::endl;
    else
        std::cout << "Not existed in array!" << std::endl;

    location = BinarySearch_Recursive(array_f, 0, sizeof(array_f) / sizeof(array_f[0]), j);
    if (location != -1)
        std::cout << "BinarySearch_Recursive:" << location + 1 << std::endl;
    else
        std::cout << "Not existed in array!" << std::endl;

    //2.判断回文数
    std::string a;
    std::cin>>a;
    if (solution.Palindrome(a) && solution.Palindrome2(a))
        std::cout << "Palindrome string" << std::endl;
    else
    {
        std::cout << "Non-palindrome string" << std::endl;
    }

    //3.打印重复出现字符
    //Example：给定字符串“ABCDBGAC”，打印“A B C”
    std::string a3;
    std::cin >> a3;
    solution.RepeatChar(a3);
    std::cout << std::endl;
    solution.RepeatChar2(a3);
    std::cout << std::endl;

    //4.🦇背景的数学公式
    int a4;
    std::cout << "你要消灭多少只蝙蝠？";
    std::cin >> a4;
    solution.mathBat(a4);*/

    //5.sortAbs 按照绝对值排序
/*    int a5;
    std::cout<<"请输入个数: ";
    while (std::cin >> a5 && a5!=0)
    {
        int a[100];
        std::cout<<"请输入数值: ";
        for (int i = 0; i<a5; i++)
            std::cin >> a[i];
        solution.sortAbs(a,a5);
    }*/


    //9.给定范围，如[10,2003]，计算该范围内所有素数的和

    /*int Start, End, sum = 0;
    do
    {
        std::cout << "Input START and END:";
        std::cin >> Start >> End;
    } while (!(Start > 0 && Start < End));
    sum = solution.sumPrimes(Start, End);
    std::cout << "The sum of all primes is " << sum << std::endl;*/


    //10.输入性别身高体重，评判体重等级。

    /*double high, weight;
    std::cout << "Please input your height in [m] :";
    std::cin >> high;
    std::cout << "Please input your Weight in [kg] :";
    std::cin >> weight;
    solution.personBMI(high,weight);*/

    //11.有序链表
/*    LinkedList<int> *linkedList = new LinkedList<int>();
    linkedList->add1(5);
    linkedList->print();
    linkedList->add1(6);
    linkedList->print();
    linkedList->add1(10);
    linkedList->print();
    linkedList->add1(7);
    linkedList->print();
    linkedList->add1(9);
    linkedList->print();
    linkedList->add1(1);
    linkedList->print();
    linkedList->add1(4);
    linkedList->print();
    linkedList->add1(2);
    linkedList->print();
    linkedList->add1(8);
    linkedList->print();
    linkedList->add1(3);
    linkedList->print();
    linkedList->add1(5);
    linkedList->print();
    linkedList->add1(6);
    linkedList->print();
    linkedList->add1(10);
    linkedList->print();*/

    //12.

    return 0;
}
