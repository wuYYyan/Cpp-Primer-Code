// 如果基类的公有成员是可访问的，那么派生类向基类的转换也是可访问的
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
        // 不论派生类以什么方式继承基类，派生类的成员函数和友元都能使用派生类向基类的转换
    }
};

class Derived3 : private Base
{

};

class Derived4 : public Derived3
{
    friend void func() {
        // Base *p = new Derived4;
        // 只有当派生类公有或受保护继承基类时，派生类的派生类的成员函数和友元才能使用派生类向基类的转换
    }
};

int main()
{
    // 只有当派生类公有继承基类时，用户代码才能使用派生类向基类的转换
    Base *p1 = new Derived1;
    // Base *p2 = new Derived2;
    // Base *p3 = new Derived3;

    return 0;
}