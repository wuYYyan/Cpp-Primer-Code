#include <iostream>
#include <string>

using namespace std;

typedef string arr[10];

string str[10];

string (&fun1(void))[10];
arr &fun2(void);
auto fun3(void) -> string (&)[10];
decltype(str) &fun4(void);

int main()
{
    
    return 0;
}

//返回包含10个string对象的数组的引用
string (&fun1(void))[10]
{

}

//使用类型别名
arr &fun2(void)
{

}

//使用尾置类型
auto fun3(void) -> string (&)[10]
{

}

//使用decltype关键字
decltype(str) &fun4(void)
{

}
