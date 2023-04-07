//相关知识点在C++ Primer P81
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "Hello", s2 = "World"; //字符串字面值可以隐式转换为string对象
    cout << s1 << ' ' << s2 << endl; //输出Hello World
    cout << "Hello" << ' ' << "World" << endl; //输出Hello World
    cout << *"Hello" << ' ' << *"World" << endl; //输出H W，这说明字符串字面值的本质是指针，否则无法取内容

    //当把string对象、字符串字面值、字符字面值混在一条语句中使用时，必须确保每个加法运算符的两侧的运算对象【至少有一个】是string对象
    string s3 = s1 + "!"; //把string对象与字符串字面值相加，依旧发生了隐式类型转换
    cout << s3 << endl; 
    string s4 = "@" + s2 + "@"; //把string对象与字符串字面值相加，依旧发生了隐式类型转换
    cout << s4 << endl; 
    //string s5 = "Hello" + "World"; //错误，两个运算对象都不是string
    string s6 = s1 + "!" + "!"; //正确，相当于s5 = (s1 + "!") + "!"
    cout << s6 << endl; 

    return 0;
}