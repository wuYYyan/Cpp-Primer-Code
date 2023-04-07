//日期：20221225
//内容：局部变量的地址与局部变量所指向的地址
#include <iostream>

using namespace std;

char *get_str();

int main()
{
    char *p = get_str();
    cout << "address = " << &p << endl;
    cout << "value = " << p << endl;
}

char *get_str()
{//函数中的局部变量存放在栈中，当函数执行结束，其中的内存空间会被系统收回

    //char str[] = {"cpp"}; //这样写什么都不会输出，因为返回的是局部变量的地址
    //static char str[] = {"cpp"}; //使用关键字static，将该字符数组放到静态存储区，其中的内存空间不会随着函数执行结束而被收回
    char *str = {"cpp"}; //使局部变量指向字符串常量，字符串常量存放在只读区域，其中的内存空间不会随着函数执行结束而被收回

    //函数执行结束后，变量str所在的内存空间一定会被系统收回，但是其所指向的内存空间不一定会被系统收回
    return str;
}