#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    double b, c = 20.6;

    b = static_cast<double>(a);
    a = static_cast<int>(c);

    // 虽然说不适用static_cast也可以转换成功，但是static_cast可以在编译时检查出类型转换是否合法
    // b = a;
    // a = c;
    // 以上两种转换方法都是直接去掉小数部分，而不是四舍五入

    cout << "b = " << b << endl;
    cout << "a = " << a << endl;

    return 0;
}