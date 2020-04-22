//
// Created by Allen on 21/4/2020.
//

#ifndef HEBUT_SOLUTION_H
#define HEBUT_SOLUTION_H

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

class Solution {
public:
    void substr(std::string str, const char a, const size_t n);

    template<typename T> int BinarySearch(T array[], int len, T value);
    template<typename T> int BinarySearch_Recursive(T array[], int low, int high, T value);

    bool Palindrome(const std::string str);
    bool Palindrome2(const std::string str);

    void RepeatChar(const std::string str);
    void RepeatChar2(const std::string str);

    void mathBat(int num);

    void sortAbs(int a[], size_t n);

    int sumPrimes(const size_t l, const size_t r);

    int personBMI(const double high, const double weight);

};

//非递归实现
template<typename T> int BinarySearch(T array[], int len, T value)
{
    if (array == NULL || len <= 0)
        return -1;

    int low = 0;
    int high = len - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == value)
            return mid;
        else if (array[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
//递归实现
template<typename T> int BinarySearch_Recursive(T array[], int low, int high, T value)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (array[mid] == value)
        return mid;
    else if (array[mid] > value)
        return BinarySearch_Recursive(array, low, mid - 1, value);
    else
        return BinarySearch_Recursive(array, mid + 1, high, value);

}




#endif //HEBUT_SOLUTION_H