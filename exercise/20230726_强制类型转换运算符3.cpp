#include <iostream>

using namespace std;

struct Base
{
    int val;
    Base(int val_ = 0) : val(val_) {}
    void showBase() const {
        cout << "Base::val = " << val << endl;
    }
};

struct Derived : public Base
{
    int val;
    Derived(int val_ = 0) : val(val_) {}
    void showDerived() const {
        cout << "Derived::val = " << val << endl;
    }
};

int main()
{
    Base b(10);
    b.showBase(); // Base::val = 10

    Derived d(20);
    d.showDerived(); // Derived::val = 20

    // b = static_cast<Base>(d);
    b = d; // 两种转换都可以成功运行
    b.showBase(); // Base::val = 0

    // d = static_cast<Derived>(b); // error
    // d.showDerived(); // Derived::val = 0

    return 0;
}