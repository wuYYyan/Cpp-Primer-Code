#include <iostream>
#include <string>

using namespace std;

void func(const string &str);

int main(void)
{
        func("ABC");  //"ABC"-->string对象，发生隐式类型转换，创建临时string对象传递给形参
        //临时string对象是右值，右值无法绑定至非常量的引用

        return 0;
}

//接受临时对象的形参必须是常量引用
void func(const string &str)
{

}