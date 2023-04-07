#include <iostream>
#include <string>

//相关知识点在C++ Primer P240 7.2小节 使用class或struct关键字

using namespace std;

struct A
{
    //struct也能定义成员函数
    void show(){cout << "Hello World" << endl;}
};

class B
{
    void show(){cout << "Good Morning" << endl;}
};
/*
使用struct与class定义类的唯一区别就是默认访问权限
在struct中，定义在第一个访问控制符之前的成员是public的
在class中，定义在第一个访问控制符之间的成员是private的
*/

int main()
{
    A a;
    a.show();

    B b;
    //b.show(); //错误，因为class的默认访问权限是private

    return 0;
}