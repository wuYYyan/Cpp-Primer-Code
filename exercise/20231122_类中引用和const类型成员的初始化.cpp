#include <iostream>

using namespace std;

/*
当类中有引用成员或const类型成员时，其默认构造函数是删除的
若要在给定构造函数中初始化，则只能在成员初始化列表中初始化，而不能在构造函数函数体中初始化
或者是在类定义时直接初始化一个已有的值(指针指向已定义的全局变量，引用绑定至已有的全局变量)
*/

class A {
    public:
        A(int n);
    private:
        int a;
        int &b;
        const int c;
};

// A::A(int n) {
//     a = n;
//     b = n;
//     c = n;
// }

A::A(int n) : a(n), b(n), c(n) {}

int main() {
    return 0;
}