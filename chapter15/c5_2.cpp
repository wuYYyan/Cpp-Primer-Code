#include <iostream>

using namespace std;

class Base {

};

// 无论以什么方式继承，派生类的友元和成员函数都能使用派生类向基类的转换
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
