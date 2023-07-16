#include <iostream>

using namespace std;

class Widget
{
    public:
        // 错误一：构造函数形参为传值，不能保证正确性
        // error: call to constructor of 'Ref' is ambiguous
        // Widget (int target) : myref(target)
        // {
        //      cout << "Ref ctor" << endl;
        // }
    
        // 错误二：函数体对引用赋值，编译错误：引用未初始化
        // error: constructor for 'Ref' must explicitly initialize the reference member 'myref'
        // Widget (int &target)  {
        //      myref = target;
        //      cout << "Ref ctor" << endl;
        // }
    
        // 如果成员变量为引用类型，那么构造函数的相应参数也为引用类型
        // 引用必须在成员初始化列表里面初始化，不能在函数体里面初始化
        // 在函数体里面修改data，相当于赋值，显然引用不能赋值
        Widget (int &target) : data(target) {
            cout << "constructor" << endl;
        }
    
        void print() {
            cout << "data value: " << data << endl;
        }

        void modified() {
            data = 20;
        }
    
        // ~Widget () {}
    
    private:
        int &data;
};

int main()
{
    cout << "Hello World!" << endl;

    int a = 10;
    Widget w(a);
    w.print();
    w.modified(); //通过在类内部修改引用类型的成员变量，间接修改了外部变量a
    cout << "a = " << a << endl;

    return 0;
}