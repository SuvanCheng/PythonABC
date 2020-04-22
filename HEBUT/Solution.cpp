//
// Created by Allen on 21/4/2020.
//

#include "Solution.h"

//1.删减字符串中特定的字符
void Solution::substr(std::string str, const char a, const size_t n) {
    size_t count = 0;
    while (str[count] == a){  //数数打头的有几个#
        count++;
    }
    if (count <= n){
        std::cout << a << std::endl; //小于等于i个#号，原样输出
    }
    else{
        str = str.substr(count - n); // get from (count - i) to the end
        std::cout << str << std::endl;
    }
}

//2.判断回文数
bool Solution::Palindrome(const std::string str){
    int i = 0;
    int j = str.size() - 1;
    for(; i < j; i++, j--){
        if(str[i] != str[j])
            break;
    }
    if(i >= j)
        return 1;
    else
        return 0;
}
bool Solution::Palindrome2(const std::string str){
    int i = 0;
    for(; i < str.size()/2; i++){
        if(str[i] != str[str.size() - 1 -i]){
            return 0;
        }
    }
    return 1;
}

//3.打印重复出现字符
//Example：给定字符串“ABCDBGAC”，打印“A B C”
struct ASCII{
    char Char;
    size_t Count;
};

void Solution::RepeatChar(const std::string str) {
    //能装128个字符数组
    ASCII a3[128];

    //初始化字符数组为128个null
    for(int i = 0; i <= 128; i++){
        a3[i].Char = 0;
        a3[i].Count = 0;
    }

    //遍历str，记录所有字母的出现频次
    for(int i = 0; str[i] != '\0'; ++i){
        a3[str[i]].Char = str[i];
        a3[str[i]].Count++;
    }

    //遍历字符数组，打印所有频次大于1次的字符
    for(int i = 0; i < 128; ++i){
        if(a3[i].Count > 1)
            std::cout << a3[i].Char << " ";
    }
    std::cout << std::endl;
}
void Solution::RepeatChar2(const std::string str) {
    //制作副本s
    std::string s = str;

    //遍历：i为基准索引，j为查询索引
    for(int i = 0; i < s.size() - 1; ++i){
        //设@为过滤字符
        if(s[i] == '@')
            continue;

        //向后查询是否复现，若复现则打印该字符，并用@替换，用m=0记录为已经打印
        int m = 1;
        for(int j = i + 1; j <= s.size() - 1; ++j){
            if(s[i] == s[j]){
                if(m == 1)
                    std::cout << s[i] << " ";
                s[j] = '@';
                m = 0;
            }
        }
    }
}

// 打蝙蝠🦇
void Solution::mathBat(int num){
    int a = 0, b = 0;
    while(num){
        if(num%2 == 0){
            num /= 2;
            a++;
        }
        else{
            num -= 1;
            b++;
        }
    }
    std::cout << "消灭所有🦇需要技能 A " << a << " 次，技能 B " << b << " 次";
}

// 绝对值排序
void Solution::sortAbs(int a[],size_t n)
{
    std::sort(a, a+n, [](const int a, const int b){ return abs(a) > abs(b); } );

    for(int i = 0; i<n; i++)
    {
        if (i)
            std::cout << " ";
        std::cout << a[i];
    }std::cout << std::endl;
}

// 素数和
int Solution::sumPrimes(size_t l, size_t r) {
    bool flag = 1;
    size_t sum = 0;
    size_t h = 0;
    std::cout << l << "......... 素数区间 ........." << r << std::endl;
    for (int i = l; i <= r; i++)
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
            std::cout << std::setw(4) << i;
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

//输入身高、体重，求BMI
struct Person
{
    double m_high;   //unit:m
    double m_weight; //unit:kg
    Person(double high, double weight) : m_high(high), m_weight(weight){};
};
int Solution::personBMI(const double high, const double weight)
{
    double BMI, w, BMItemp;
    Person person(high,weight);
    BMI = person.m_weight / pow(person.m_high, 2); //BMI指数公式
    std::cout << "Your BMI is " << BMI << std::endl;
    w = person.m_weight;
    if (BMI <= 23.9 && BMI >= 18.5)
    {
        std::cout << "You are in standard value!!!\n";
    }
    else if (BMI < 18.5)
    {
        do
        {
            w += 0.5;
            BMItemp = w / pow(person.m_high, 2);
        } while (BMItemp < 18.5);
        std::cout << "You will gain " << (w - person.m_weight) << " kg "
             << "to acheive the standard!\n";
    }
    else
    {
        do
        {
            w -= 0.5;
            BMItemp = w / pow(person.m_high, 2);
        } while (BMItemp > 23.9);
        std::cout << "You will lose " << (person.m_weight - w) << " kg "
             << "to acheive the standard!\n";
    }
    return 0;
}

//

