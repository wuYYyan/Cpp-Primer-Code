#include <iostream>

using namespace std;

class Base {

};

// ������ʲô��ʽ�̳У����������Ԫ�ͳ�Ա��������ʹ��������������ת��
class Derived1 : public Base {
    friend void f1();
    void f2() {
        Base *pb = new Derived1();
    }
};

void f1() {
    Derived1 d1;
    Base b1 = d1;
}

class Derived2 : protected Base {

};

class Derived3 : private Base {

};

int main() {
    return 0;
}
