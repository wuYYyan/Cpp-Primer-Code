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
        A a;

    public:
        void show() {a.show();}
};

int main()
{
    B b; //类B将使用系统提供的合成默认构造函数，而先将调用A的默认构造函数
    b.show();

    return 0;
}