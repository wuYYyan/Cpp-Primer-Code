#include <iostream>

using namespace std;

class B
{
    private:
        int val;
    public:
        B() {cout << "Good Morning" << endl;}
        B(int n) : val(n) {cout << "Hello World" << endl;}
};

class A
{
    private:
        B b;
    public:
        //A(int v) : b(v) {} //成员初始化列表方式
        A(int v) {b = v;} //赋值方式，相当于先调用默认构造函数初始化，再调用含参构造函数赋值
};

int main()
{
    int x = 10;
    A a(x);

    return 0;
}