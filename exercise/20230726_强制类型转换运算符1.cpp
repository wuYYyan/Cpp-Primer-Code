#include <iostream>

using namespace std;

class Base
{
    public:
        virtual void fun1() const {}
        void showBase() const  {
            cout << "Base::showBase()" << endl;
        }
};

class Derived : public Base
{
    public:
        virtual void fun1() const override {}
        void showDerived() const {
            cout << "Derived::showDerived()" << endl;
        }
};

int main()
{
    Base *pb;
    Base *pb1 = new Base();
    Base *pb2 = new Derived(); //基类的指针或引用可以绑定至派生类的对象
    pb2->showBase();
    // pb2->showDerived();
    // 虽然基类的指针可以指向派生类的对象，但是也只能调用基类中的成员
    // 因为决定一个对象的可调用范围还是它的静态类型，而不是它的动态类型

    Derived *pd;
    Derived *pd1 = dynamic_cast<Derived *>(pb1); // pb1指向的对象不是派生类对象，所以转换失败，pd1为nullptr
    pd1->showBase();
    pd1->showDerived();
    // Derived *pd1 = pb1; //基类的指针转换为派生类的指针必须使用强制类型转换
    
    if (pd1 == nullptr)
        cout << "转换失败！" << endl; // 确实转换失败，分析地没错
        // 但是因为nullptr可以隐式地转换为各类指针类型，所以可以调用成员函数成功
    else
        cout << "转换成功！" << endl;

    Derived *pd2 = dynamic_cast<Derived *>(pb2); // pb2指向的对象是派生类对象，所以转换成功，pd2指向pb2指向的对象
    pd2->showBase();
    pd2->showDerived();

    // pb = dynamic_cast<Derived *>(pd);
    pb = pd; //派生类的指针可以直接转换为基类的指针，无需dynamic_cast强制类型转换
    
    return 0;
}