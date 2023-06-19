#include <iostream>

using namespace std;

int main()
{
    int r = 42;
    int &r1 = r; //左值引用，绑定到对象上
    // int &&rr1 = r; //error，无法将右值引用绑定到左值上
    int &&rr2 = 42; //右值引用，绑定到右值类型(字面值)上
    int &&rr3 = r * 2; //右值引用，绑定到右值类型(表达式)上
    const int &r3 = r; //const左值引用可以绑定到右值上
    // int &&rr4 = r3; //error，右值引用类型的变量本身是左值，无法将右值引用绑定到左值上

    return 0;
}