#include <iostream>

using namespace std;

struct A1
{

};

struct A2
{
    A2(); // 构造函数
    A2(const A2& a2); // 拷贝构造函数
    ~A2(); // 析构函数
    A2& operator=(const A2& a2); // 拷贝复制运算符
    A2* operator&(); // 取址运算符
    const A2* operator&() const; // 取址运算符(const版本)
};

struct A3
{
    A3(); // 构造函数
    A3(const A3& a2); // 拷贝构造函数
    virtual ~A3(); // 析构函数
    A3& operator=(const A3& a2); // 拷贝复制运算符
    A3* operator&(); // 取址运算符
    const A3* operator&() const; // 取址运算符(const版本)
};

int main()
{
    cout << sizeof(A1) << endl; // 1
    cout << sizeof(A2) << endl; // 1
    cout << sizeof(A3) << endl; // 8
    // 这就是为什么cpp不会将默认的析构函数设置为虚函数的原因

    return 0;
}