#include <iostream>

using namespace std;

class A
{
    private:
        int n1;
        int n2;
    public:
        //默认构造函数，要么不提供任何形参，要不为所有形参提供默认值
        A() : n2(1), n1(n2 + 2) {}
        //成员变量被初始化的顺序是它们被声明的顺序，而不是它们在初始化列表中的顺序
        void print()
        {
            cout << "n1 = " << n1 << endl;
            cout << "n2 = " << n2 << endl;
        }
};

int main()
{
    A a;
    a.print();

    return 0;
}