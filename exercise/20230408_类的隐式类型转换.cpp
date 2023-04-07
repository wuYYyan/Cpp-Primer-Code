#include <iostream>
#include <string>

//相关知识点在C++ Primer P263 7.5.4小节 隐式的类类型转换

using namespace std;

class A
{
    private:
        string str;
        int x = 0;
    public:
        A() {} //凡是自己提供了构造函数，则一定要写一个默认构造函数
        //默认构造函数可以不带任何参数，也可以为所有参数设置默认值
        A(const string s) : str(s) {}
        void show() {cout << str << " " << x << endl;}
        void test(const A &a) {str = a.str; x = a.x + 1;}
};

int main()
{
    //隐式类型转换发生的基础：存在能通过一个实参调用的构造函数
    A a1("hello");
    a1.show();

    //编译器只会自动执行一步类型转换
    A a2, a3, a4;
    //a2.test("hello"); //错误，如果要调用的话则进行了两次隐式类型转换：字符串字面值 -> string对象 -> 类A的对象
    a2.test(a1); //没有发生隐式类型转换
    a2.show();
    a3.test(A("hello")); //字符串字面值隐式转换为string对象，string对象显式转换为类A的对象
    a3.show();
    a4.test(string("hello")); //字符串字面值显式转换为string对象，string对象隐式转换为类A的对象
    a4.show();

    //使用关键字explicit阻止隐式类型转换，但是依然可以显式类型转换

    return 0;
}