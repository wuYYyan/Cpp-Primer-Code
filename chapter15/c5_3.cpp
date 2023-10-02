#include <iostream>

using namespace std;

class Base {

};

// 无论以什么方式继承，派生类的友元和成员函数都能使用派生类向基类的转换
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

// 无论派生类再以何种方式产生新的派生类，新派生类的友元和成员函数都能使用派生类向基类的转换
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