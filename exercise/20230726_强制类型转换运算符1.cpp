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
    Base *pb2 = new Derived(); //�����ָ������ÿ��԰���������Ķ���
    pb2->showBase();
    // pb2->showDerived();
    // ��Ȼ�����ָ�����ָ��������Ķ��󣬵���Ҳֻ�ܵ��û����еĳ�Ա
    // ��Ϊ����һ������Ŀɵ��÷�Χ�������ľ�̬���ͣ����������Ķ�̬����

    Derived *pd;
    Derived *pd1 = dynamic_cast<Derived *>(pb1); // pb1ָ��Ķ������������������ת��ʧ�ܣ�pd1Ϊnullptr
    pd1->showBase();
    pd1->showDerived();
    // Derived *pd1 = pb1; //�����ָ��ת��Ϊ�������ָ�����ʹ��ǿ������ת��
    
    if (pd1 == nullptr)
        cout << "ת��ʧ�ܣ�" << endl; // ȷʵת��ʧ�ܣ�������û��
        // ������Ϊnullptr������ʽ��ת��Ϊ����ָ�����ͣ����Կ��Ե��ó�Ա�����ɹ�
    else
        cout << "ת���ɹ���" << endl;

    Derived *pd2 = dynamic_cast<Derived *>(pb2); // pb2ָ��Ķ������������������ת���ɹ���pd2ָ��pb2ָ��Ķ���
    pd2->showBase();
    pd2->showDerived();

    // pb = dynamic_cast<Derived *>(pd);
    pb = pd; //�������ָ�����ֱ��ת��Ϊ�����ָ�룬����dynamic_castǿ������ת��
    
    return 0;
}