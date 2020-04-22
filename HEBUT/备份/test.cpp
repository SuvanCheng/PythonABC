#include <iostream>

struct MyStruct{
    int a;
    char b;
    long c;
};

int main(){
    MyStruct x;
    MyStruct arr[] = {1,'a',1.1,2,'b',2.2,3,'c',3.3};

    x.a = 4;
    x.b = 'd';
    x.c = 4.4;

    std::cout << x.b << std::endl;
}