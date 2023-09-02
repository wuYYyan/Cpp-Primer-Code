// 如果类中含有引用类型的成员变量，则该类型的合成默认构造函数被定义为删除的
#include <iostream>

using namespace std;

int x = 1;

class A
{
    private:
        int &r; // 引用类型的成员变量在构造函数的初始化列表中进行初始化
};

class B
{
    private:
        int &r = x; // 可以在类声明时为引用成员变量提供初始值
};

class C
{
    private:
        // int &r = 1; // error，无法将左值引用绑定到右值(字面值常量)上
};

int main()
{
    // 引用类型的变量在声明时必须同时初始化
    // int &r;

    int &r1 = x;

    cout << sizeof(int)  << endl; // 4
    cout << sizeof(r1) << endl; // 4
    cout << sizeof(A) << endl; // 8(why?)
    cout << sizeof(B) << endl; // 8(why?)
    cout << sizeof(C) << endl; // 1

    // A a; // error: use of deleted function 'A::A()'
    B b; // ok

    return 0;
}