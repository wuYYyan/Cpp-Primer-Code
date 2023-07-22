#include <iostream>

using namespace std;

class One
{

};

class Two
{
    public:
        Two() {}
        ~Two() {}
};

class Three
{
    public:
        Three() {}
        ~Three() {}
        virtual void fun() {}
};

class Four
{
    public:
        Four() {}
        ~Four() {}
        virtual void fun() {}
        virtual void fun1() {}
};

class Five
{
    public:
        int data;
        Five() {}
        ~Five() {}
        virtual void fun() {}
};

int main()
{
    cout << "sizeof(One): " << sizeof(One) << endl; //1，系统为空类生成一字节的占位符
    cout << "sizeof(Two): " << sizeof(Two) << endl; //1，非虚函数不生成虚指针
    cout << "sizeof(Three): " << sizeof(Three) << endl; //8,通过虚指针指向的虚表调用虚函数
    cout << "sizeof(Four): " << sizeof(Four) << endl; //8，不管有几个虚函数都只有一个虚指针，虚函数的增加只会扩充虚表
    cout << "sizeof(Five): " << sizeof(Five) << endl; //16，涉及到内存对齐问题
    // 和结构体内存对齐的道理一样，虚指针会从自身对齐数的整数倍位置开始分配内存

    return 0;
}