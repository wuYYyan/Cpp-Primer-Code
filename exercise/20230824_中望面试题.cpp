#include <iostream>

using namespace std;

struct A
{
    virtual void func1() const { cout << "A::func1()" << endl; }
    virtual void func2() const { cout << "A::func2()" << endl; }
};

// 在派生类中关键字virtual可写可不写，因为在一个继承体系中
// 一旦某个函数被声明为虚函数，那么在所有的派生类中它都是虚函数
struct B : public A
{
    virtual void func1() const override { cout << "B::func1()" << endl; } // 重写/覆盖
    // virtual void func1() override const { cout << "B::show()" << endl; }
    virtual void func2() const override { cout << "B::func2()" << endl; } // 重写/覆盖
};

struct C : public B
{
    virtual void func1() const override { cout << "C::func1()" << endl; } // 重写/覆盖
    virtual void func2() const override { cout << "C::func2()" << endl; } // 重写/覆盖
    virtual void func3() const { cout << "C::func3()" << endl; }
};

struct D : public C
{
    virtual void func1() const override { cout << "D::func1()" << endl; } // 重写/覆盖
    virtual void func2() const override { cout << "D::func2()" << endl; } // 重写/覆盖
    void func3(int a) const { cout << "D::func3(int)" << endl; }
    // 派生类的成员与基类成员的参数列表不同，由于遵循名字查找有限原则，派生类的成员会隐藏基类的成员
};

int main()
{
    D *pd = new D();

    pd->func1();
    pd->func2();

    pd->A::func1();
    pd->A::func2();
    pd->B::func1();
    pd->B::func2();
    pd->C::func1();
    pd->C::func2();

    pd->func3(1);
    pd->C::func3();

    return 0;
}