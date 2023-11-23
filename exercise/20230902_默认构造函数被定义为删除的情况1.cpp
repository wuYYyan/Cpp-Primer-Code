// 如果类中含有const成员变量，则该类型的合成默认构造函数被定义为删除的(= delete)
#include <iostream>

using namespace std;

int x = 1;

class A
{
    private:
        const int a; // const类型的成员变量可以随不同的实例化对象而不同
};

class B
{
    private:
        const int a = x;
        // 可以在类声明中直接初始化const类型的成员变量
        // 这样所有该类的对象的这个成员变量的值都一样
};

class C
{
    public:
        C(int a_) : a(a_) {} // 可以在构造函数的初始化列表中初始化const类型的成员变量
    private:
        const int a;
};

// const int C::a = 100;
// error，非静态数据成员不能在类外部初始化
// 若为静态成员变量在类外进行初始化时，不再需要static关键字

int main()
{
    // const变量在声明时必须同时初始化
    // const int a;

    const int a1 = 100;

    cout << sizeof(int)  << endl; // 4
    cout << sizeof(a1) << endl; // 4
    cout << sizeof(A) << endl; // 4
    cout << sizeof(B) << endl; // 4
    cout << sizeof(C) << endl; // 4

    // A a; // error: use of deleted function 'A::A()'
    B b; // ok
    // C c; // error: use of deleted function 'C::C()'
    C c(1); // ok

    return 0;
}