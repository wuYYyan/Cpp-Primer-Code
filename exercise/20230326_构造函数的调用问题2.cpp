#include <iostream>

using namespace std;

class A
{
    public:
        A() {cout << "1)" << endl;}
        A(int x) {cout << "2)" << endl;}
};

int main()
{
    A a1;
    A a2(2);
    A *pa1; //并没有调用构造函数，只有在创建对象、为对象开辟内存空间时才会调用构造函数
    A *pa2 = new A;

    return 0;
}