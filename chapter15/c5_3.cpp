#include <iostream>

using namespace std;

class Base {

};

// ������ʲô��ʽ�̳У����������Ԫ�ͳ�Ա��������ʹ��������������ת��
class Derived : public Base {
    friend void f1();
    void f2() {
        Base *pb = new Derived();
    }
};

void f1() {
    Derived d;
    Base b = d;
}

// �������������Ժ��ַ�ʽ�����µ������࣬�����������Ԫ�ͳ�Ա��������ʹ��������������ת��
class DDerived : protected Derived {
    friend void ff1();
    void ff2() {
        Base *pb = new Derived();
    }
};

void ff1() {
    Derived d;
    Base b = d;
}

int main() {
    return 0;
}