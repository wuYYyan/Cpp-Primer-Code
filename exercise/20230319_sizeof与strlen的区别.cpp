#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a = 4;
    //操作符sizeof()的参数可以是变量的类型，也可以是变量名
    cout << sizeof(int) << ' ' << sizeof(a) << endl; //输出均为4

    char p[10] = "wuyan";
    char q[] = "WUYAN";
    cout << sizeof(p) << ' ' << strlen(p) << endl; //前者输出10，后者输出5
    cout << sizeof(q) << ' ' << strlen(q) << endl; //前者输出6，后者输出5
    //说明操作符sizeof()返回的是变量所占内存的大小(自动添加空字符)，而函数strlen()返回的是字符串的长度，还不包含空字符
    //在sizeof运算符中，不会将数组名解释为第一个元素的地址(C++ Primer P143：数组不会转换为指针的五种情况)

    return 0;
}