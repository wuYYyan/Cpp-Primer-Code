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
    Base *pb2 = new Derived; //�����ָ������ÿ��԰���������Ķ���

    Derived *pd;
    Derived *pd1 = dynamic_cast<Derived *>(pb1); //pb1ָ��Ķ������������������ת��ʧ�ܣ�pd1Ϊnullptr
    Derived *pd2 = dynamic_cast<Derived *>(pb2); //pb2ָ��Ķ������������������ת���ɹ���pd2ָ��pb2ָ��Ķ���

    pb = dynamic_cast<Derived *>(pd);
    return 0;
}