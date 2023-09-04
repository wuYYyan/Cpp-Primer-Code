#include <iostream>

using namespace std;

// void func(int *p)
// {
//     cout << "func(int *p)" << endl;
// }

class A
{

};

void func(A *p)
{
    cout << "func(A *p)" << endl;
}

// void func(int p)
// {
//     cout << "func(int p)" << endl;
// }

// void func(char *p)
// {
//     cout << "func(char *p)" << endl;
// }

int main()
{
    // func(nullptr); // func(char *p)
    // nullptr可以隐式转化为各种指针类型，包含内置指针类型和自定义的类指针类型
    
    func(NULL);
    // NULL既能隐式转化为内置指针类型与自定义的类指针类型，也能转化为其他内置类型

    cout << sizeof(nullptr) << endl; // 8
    cout << sizeof(NULL) << endl; // 8

    return 0;
}