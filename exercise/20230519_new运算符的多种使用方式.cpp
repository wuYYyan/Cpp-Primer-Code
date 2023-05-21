#include <iostream>

using namespace std;

int main()
{
    int *p1 = new int;
    *p1 = 10;
    cout << "*p1 = " << *p1 << endl;

    int *p2 = new int(20); //开辟内存空间，构造对象
    cout << "*p2 = " << *p2 << endl;

    int *p3 = new int[10]; //10个未被初始化的int，里面存放的是垃圾值
    cout << "*p3 = " << *p3 << endl;

    int *p4 = new int[10](); //10个初始化为0的int
    cout << "*p4 = " << *p4 << endl;

    int *p5 = new int[10]{1, 2, 3, 4, 5}; //10个初始化为1, 2, 3, 4, 5, 0, 0, 0, 0, 0的int
    cout << "*p5 = " << *p5 << endl;

    const int *p6 = new const int[10](); //10个初始化为0的const int
    //*p6 = 10; //error，不能修改*p6的值
    cout << "*p6 = " << *p6 << endl;

    int *p7 = new (nothrow) int; //不抛出异常，开辟失败返回0，即一般默认分配失败时抛出异常
    // nothrow是由标准库定义的对象，存放在头文件<new>中
    if (p7 == 0)
        cout << "p7 is null" << endl;
    cout << "*p7 = " << *p7 << endl;

    int data = 0;
    int *p8 = new (&data) int(1); //在data的地址上构造一个int对象
    // 定位new表达式允许用户向new传递额外的参数，这些参数被传递给operator new函数
    cout << "*p8 = " << *p8 << endl;
    cout << "data = " << data << endl;
}