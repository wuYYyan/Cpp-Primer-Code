#include <iostream>

using namespace std;

class Base
{
    virtual void fun() {}
};

class Derived : public Base
{
    virtual void fun() const {}
};

int main()
{
    Base *pb;
    Base *pb1 = new Base;
    Base *pb2 = new Derived; //基类的指针或引用可以绑定至派生类的对象

    Derived *pd;
    Derived *pd1 = dynamic_cast<Derived *>(pb1); //pb1指向的对象不是派生类对象，所以转换失败，pd1为nullptr
    Derived *pd2 = dynamic_cast<Derived *>(pb2); //pb2指向的对象是派生类对象，所以转换成功，pd2指向pb2指向的对象

    pb = dynamic_cast<Derived *>(pd);
    return 0;
}