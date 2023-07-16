// GDB
#include <iostream>

using namespace std;

class A
{
    public:
        void show()
        {
            cout << "a = " << a << endl;
        }

    private:
        int a;
};

int main()
{
    cout << "Hello World!" << endl;
    
    A a; //默认构造函数对提供类内初始值的成员变量进行值初始化
    a.show();

    // int a = 0, b = 10;
    // cout << "a = " << a << endl;

    // a += b;
    // cout << "a = " << a << endl;

    // int i = 1;
    // int &j = i;
    // int &k = j;

    return 0;
}
