#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[] = "flower";

    //提示：ISO C++ forbids converting a string constant to 'char*'
    char *p = "dog";
    char *q = "cat";

    cout << sizeof(a) << " " << strlen(a) << endl;
    //sizeof运算符计算的是变量所占内存的大小，因此计入结束符'\0'，输出7
    //strlen函数返回的是字符串的长度，因此不计入结束符'\0'，输出6

    cout << a << " " << p << " " << q << endl;
    //将字符指针传递给cout智能对象，会一直输出直到遇到空字符为止

    p = q; //p与q指向同一内存空间
    //a = q; //报错，因为数组名本质上是个常量，无法对其赋值

    cout << p << " " << q << endl;

    return 0;
}