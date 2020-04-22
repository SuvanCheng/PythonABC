#include <iostream>
#include <string>
using namespace std;

bool testPalindrome(const string s){
    int i = 0;
    int j = s.size() - 1;
    for(; i < j; i++, j--){
        if(s[i] != s[j])
            break;
    }
    if(i >= j)
        return 1;
    else
        return 0;
}
bool testPalindrome2(const string s){
    int i = 0;
    for(; i < s.size()/2; i++){
        if(s[i] != s[s.size() - 1 -i]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    string a;
    cin>>a;
    if (testPalindrome(a) && testPalindrome2(a))
        cout << "Palindrome string" << endl;
    else
    {
        cout << "Non-palindrome string" << endl;
    }
}
