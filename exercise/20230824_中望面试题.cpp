#include <iostream>

using namespace std;

struct A
{
    virtual void func1() const { cout << "A::func1()" << endl; }
    virtual void func2() const { cout << "A::func2()" << endl; }
};

// ���������йؼ���virtual��д�ɲ�д����Ϊ��һ���̳���ϵ��
// һ��ĳ������������Ϊ�麯������ô�����е����������������麯��
struct B : public A
{
    virtual void func1() const override { cout << "B::func1()" << endl; } // ��д/����
    // virtual void func1() override const { cout << "B::show()" << endl; }
    virtual void func2() const override { cout << "B::func2()" << endl; } // ��д/����
};

struct C : public B
{
    virtual void func1() const override { cout << "C::func1()" << endl; } // ��д/����
    virtual void func2() const override { cout << "C::func2()" << endl; } // ��д/����
    virtual void func3() const { cout << "C::func3()" << endl; }
};

struct D : public C
{
    virtual void func1() const override { cout << "D::func1()" << endl; } // ��д/����
    virtual void func2() const override { cout << "D::func2()" << endl; } // ��д/����
    void func3(int a) const { cout << "D::func3(int)" << endl; }
    // ������ĳ�Ա������Ա�Ĳ����б�ͬ��������ѭ���ֲ�������ԭ��������ĳ�Ա�����ػ���ĳ�Ա
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