#include <iostream>

using namespace std;

class A
{
    private:
        int n;
    public:
        A(){n = 200;}
        void show() {cout << "n = " << n << endl;}
};

class B
{
    private:
        int x;
        A a;

    public:
        B(int a) : x(a) {}
        void show() {cout << "x = " << x << endl; a.show();} 
};

int main()
{
    B b(10); //在B的构造函数中，类A的对象并没有被显示的初始化，则将调用A的默认构造函数
    b.show();

    return 0;
}