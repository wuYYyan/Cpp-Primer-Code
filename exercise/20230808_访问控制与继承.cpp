// �������Ĺ��г�Ա�ǿɷ��ʵģ���ô������������ת��Ҳ�ǿɷ��ʵ�
#include <iostream>

using namespace std;

class Base
{

};

class Derived1 : public Base
{

};

class Derived2 : protected Base
{
    friend void func() {
        Base *p = new Derived2;
        // ������������ʲô��ʽ�̳л��࣬������ĳ�Ա��������Ԫ����ʹ��������������ת��
    }
};

class Derived3 : private Base
{

};

class Derived4 : public Derived3
{
    friend void func() {
        // Base *p = new Derived4;
        // ֻ�е������๫�л��ܱ����̳л���ʱ���������������ĳ�Ա��������Ԫ����ʹ��������������ת��
    }
};

int main()
{
    // ֻ�е������๫�м̳л���ʱ���û��������ʹ��������������ת��
    Base *p1 = new Derived1;
    // Base *p2 = new Derived2;
    // Base *p3 = new Derived3;

    return 0;
}