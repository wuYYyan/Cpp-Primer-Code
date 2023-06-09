#include <iostream>

using namespace std;

class numbered
{
    private:
        static int id;
    public:
        int mysn;
        numbered() { mysn = id++; }
        numbered(const numbered &n) { mysn = id++; } //拷贝构造函数
};

int numbered::id = 0; //静态成员初始化

void f(numbered s)
{
    cout << s.mysn << endl;
}   //按值传递参数，会调用拷贝构造函数

void f1(numbered &s)
{
    cout << s.mysn << endl;
}   //按引用传递参数，不会调用拷贝构造函数

int main()
{
    numbered a, b = a, c = b; //b、c的初始化调用拷贝构造函数，手动增加static数据成员，然后赋值给每个对象自身的mysn数据成员
    f(a); //按值传递参数调用拷贝构造函数，下同
    f(b);
    f(c);

    cout << "-------------" << endl;

    f1(a);
    f1(b);
    f1(c);

    return 0;
}