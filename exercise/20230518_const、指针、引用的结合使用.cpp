#include <iostream>

using namespace std;

int main()
{
    // 代码实现：在内存的0x0018ff44地址处构造一个int对象，值为10
    // 注意这个地址不要随意改变，否则可能更改系统的重要数据，导致系统崩溃

    // 方法一：使用定位new运算符
    int *p1 = new ((int*)0x0018ff44) int(10);
    cout << "*p1 = " << *p1 << endl;

    // 方法二：使用引用
    // const int *&p2 = (int*)0x0018ff44; //p是一个对指向0x0018ff44地址处、可存放int类型数据的指针的常量引用
    // *p2 = 10;
    // cout << "*p2 = " << *p2 << endl;

    return 0;
}