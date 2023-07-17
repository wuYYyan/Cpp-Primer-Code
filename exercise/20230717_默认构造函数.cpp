#include <iostream>

using namespace std;

class A
{
    public:
        void show()
        {
            cout << "A::a = " << a << endl;
        }

    private:
        int a;
};

struct B
{
    void show()
    {
        cout << "B::b = " << b << endl;
    }
    int b;
};

int main()
{
    A a; //默认构造函数对提供类内初始值的成员变量进行值初始化
    a.show();

    B b;
    b.show();

    return 0;
}
