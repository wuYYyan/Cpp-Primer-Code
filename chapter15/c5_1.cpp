#include <iostream>

using namespace std;

class Base {

};

class Derived1 : public Base {

};

class Derived2 : protected Base {

};

class Derived3 : private Base {

};

int main() {
    // ֻ�е��̳з�ʽ�ǹ��е�ʱ���û��������ʹ��������������ת��
    Derived1 d1;
    Base b1 = d1;

    // ����̳з�ʽ��˽�еĻ��ܱ����ģ����û����벻��ʹ��������������ת��
    // Derived2 d2;
    // Base b2 = d2;

    // Derived3 d3;
    // Base b3 = d3;

    return 0;
}