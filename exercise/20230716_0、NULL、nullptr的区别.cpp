#include <iostream>

using namespace std;

typedef decltype(nullptr) nullptr_t;

int fun(int) { cout << "int" << endl; }
int fun(int *) { cout << "int *" << endl; }
int fun(nullptr_t) { cout << "nullptr_t" << endl; }

int main()
{
    cout << sizeof(0) << endl; //4
    cout << sizeof(NULL) << endl; //8
    cout << sizeof(nullptr) << endl; //8

    int *p = NULL; //NULL是一个宏定义，值为0
    // 上述语句也侧面说明了如果NULL是指针类型，那么它赋给p时需要进行类型转换
    // 然后不需要类型转换也可以编译通过，说明NULL是一个宏定义，值为0(C++ 11)
    // 在C++ 11之后，NULL是nullptr的纯右值

    fun(0);
    // fun(NULL); //报错，有多个匹配
    fun(nullptr);

    return 0;
}