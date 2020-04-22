#include <iostream>
using namespace std;

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

int main(int argc, char* argv[])
{
    double a[] = { 1.79, 1.80, 1.81, 1.82, 1.83, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.90, 1.91, 1.92 };
    double j;

    cout << "Input the search number:";
    cin >> j;
    

    int location = BinarySearch(a, sizeof(a) / sizeof(a[0]), j);
    if (location != -1)
        cout << "BinarySearch:" << location + 1 << endl;
    else
        cout << "Not existed in array!" << endl;

    location = BinarySearch_Recursive(a, 0, sizeof(a) / sizeof(a[0]), j);
    if (location != -1)
        cout << "BinarySearch_Recursive:" << location + 1 << endl;
    else
        cout << "Not existed in array!" << endl;
    return 0;
}