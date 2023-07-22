#include <iostream>

using namespace std;

class Base
{
    public:
        virtual void fun1() const {}
};

class Derived : public Base
{
    public:
        virtual void fun1() const override {}
        void fun2() const {}
};

int main()
{
    Base *pb;
    Base *pb1 = new Base;
    Base *pb2 = new Derived; //基类的指针或引用可以绑定至派生类的对象
    // pb2->fun2();
    // 虽然基类的指针可以指向派生类的对象，但是也只能调用基类中的成员

    Derived *pd;
    Derived *pd1 = dynamic_cast<Derived *>(pb1); //pb1指向的对象不是派生类对象，所以转换失败，pd1为nullptr
    // Derived *pd1 = pb1; //基类的指针转换为派生类的指针必须使用强制类型转换
    Derived *pd2 = dynamic_cast<Derived *>(pb2); //pb2指向的对象是派生类对象，所以转换成功，pd2指向pb2指向的对象
    pd1->fun2();
    pd2->fun2();

    // pb = dynamic_cast<Derived *>(pd);
    pb = pd; //派生类的指针可以直接转换为基类的指针，无需dynamic_cast强制类型转换
    
    return 0;
}