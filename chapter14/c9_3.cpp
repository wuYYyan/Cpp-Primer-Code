#include <iostream>

using namespace std;

class A
{
    friend int operator+(A &a, int x);
    private:
        int n;
    public:
        A() : n(10) { }
        // operator int() const { return n; }
        int operator+(int x) { return this->n + x; }
};

int operator+(A &a, int x)
{
    return a.n + x;
}

int main()
{
    A a;

    // cout << a + 20 << endl; //调用类型转换运算符
    // cout << a + 20 << endl; //调用重载的类内加法运算符
    // cout << a + 20 << endl; //调用重载的友元加法运算符

    // 对于类的成员函数和非成员函数的调用方式不同，因此不会发生冲突
    cout << a.operator+(20) << endl;
    cout << operator+(a, 20) << endl;

    return 0;
}