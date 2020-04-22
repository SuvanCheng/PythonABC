#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    size_t count = 0;
    size_t i;
    cout << "Input a String: ";
    cin >> a;
    cout << "Input a Number: ";
    cin >> i;
    while (a[count] == '#'){  //数数打头的有几个#
        count++;
    }
    if (count <= i){
        cout << a << endl; //小于等于i个#号，原样输出
    }
    else{
        a = a.substr(count - i); // get from (count - i) to the end
        cout << a << endl;
    }
    return 0;
}
