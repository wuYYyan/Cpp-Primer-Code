#include <iostream>

struct A
{
    int val = 42;
    virtual void fun(){std::cout << "A::fun" << std::endl;}
};
struct B : public A
{ 
    void fun() override {std::cout << "B::fun" << std::endl;}
};
struct C : public A
{ 
    void fun() override {std::cout << "C::fun" << std::endl;}
};
struct D : public B, public C
{
    void fun() override {std::cout << "D::fun" << std::endl;}
};

int main(int argc, char const *argv[])
{
    D d;
    // std::cout << d.val << std::endl; //����ʧ�ܣ���֪�����ô��ĸ����м̳е�val����
    d.fun(); 

    return 0;
}