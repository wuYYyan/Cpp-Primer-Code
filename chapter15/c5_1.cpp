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
    // 只有当继承方式是公有的时候，用户代码才能使用派生类向基类的转换
    Derived1 d1;
    Base b1 = d1;

    // 如果继承方式是私有的或受保护的，则用户代码不能使用派生类向基类的转换
    // Derived2 d2;
    // Base b2 = d2;

    // Derived3 d3;
    // Base b3 = d3;

    return 0;
}