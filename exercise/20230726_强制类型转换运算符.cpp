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
    Base *pb2 = new Derived; //�����ָ������ÿ��԰���������Ķ���
    // pb2->fun2();
    // ��Ȼ�����ָ�����ָ��������Ķ��󣬵���Ҳֻ�ܵ��û����еĳ�Ա

    Derived *pd;
    Derived *pd1 = dynamic_cast<Derived *>(pb1); //pb1ָ��Ķ������������������ת��ʧ�ܣ�pd1Ϊnullptr
    // Derived *pd1 = pb1; //�����ָ��ת��Ϊ�������ָ�����ʹ��ǿ������ת��
    Derived *pd2 = dynamic_cast<Derived *>(pb2); //pb2ָ��Ķ������������������ת���ɹ���pd2ָ��pb2ָ��Ķ���
    pd1->fun2();
    pd2->fun2();

    // pb = dynamic_cast<Derived *>(pd);
    pb = pd; //�������ָ�����ֱ��ת��Ϊ�����ָ�룬����dynamic_castǿ������ת��
    
    return 0;
}