#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    public:
        HasPtr() {}

        // 当形参是某种类型的引用时，通过区分常量引用还是非常量引用构成重载
        // HasPtr(string &s = string()) : ps(new string(s)), i(0) { } //形参给定默认时生成的临时变量为右值，而引用类型的变量为左值，左值无法绑定到右值。所以会报错
        HasPtr(const string &s = string()) : ps(new string(s)), i(0) { } //例外：const的左值引用可以绑定到右值

        // 当形参是某种类型的指针时，通过区分常量指针还是非常量指针构成重载
        HasPtr(string *ptr = new string()) : ps(ptr), i(0) { }
        // HasPtr(const string *ptr = new string()) : ps(ptr), i(0) { }

        HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { } //拷贝构造函数
        HasPtr &operator=(const HasPtr &); //拷贝赋值运算符

        HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = nullptr; p.i = 0; } //移动构造函数
        HasPtr &operator=(HasPtr &&) noexcept; //移动赋值运算符

        // 使用友元函数swap的赋值运算符，按值传递参数，属于函数重载
        // 既是拷贝赋值运算符，又是移动赋值运算符，所以在实际使用时会造成二义性调用
        // HasPtr &operator=(HasPtr rhs) { swap(*this, rhs); return *this; }

        // 交换操作，定义为友元函数
        friend void swap(HasPtr &lhs, HasPtr &rhs);

        ~HasPtr() { delete ps;} //析构函数

        // 构成函数重载
        void show() { cout << "non-const show(): " << *ps << endl;}
        void show() const { cout << "const show(): " << *ps << endl;}
    private:
        string *ps;
        int i;
};

// 拷贝赋值运算符结合了析构函数和拷贝构造函数的工作
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

// 移动赋值运算符结合了析构函数和移动构造函数的工作
HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
    if (this != &rhs)
    {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    return *this;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    // HasPtr hp; //类HasPtr包含多个默认构造函数，所以会报错
    HasPtr hp1("Hello World!");
    hp1.show();
    const HasPtr hp2("Good morning!");
    hp2.show();

    HasPtr hp3("Good luck!");
    // 在不发生二义性调用的前提下：1)调用拷贝赋值运算符，2)调用赋值运算符重载函数，按值传递参数，使用拷贝构造函数拷贝hp3
    hp1 = hp3; //左值可以赋给左值，也可以按值传递给形参(左值)
    // 在不发生二义性调用的前提下：1)调用移动赋值运算符，2)调用赋值运算符重载函数，按值传递参数，使用移动构造函数移动hp3
    hp1 = std::move(hp3); //右值可以赋给右值引用，可以按照传递给形参(左值)
    // 因为按值传递参数本质上是创建了新的临时对象

    return 0;
}