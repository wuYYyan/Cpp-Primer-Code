#include <iostream>

using namespace std;

class A
{
    private:
        int len;
    public:
        A(int n) : len(n) {}

        void print()
        {
            cout << &len << ": " << len << endl;
        }
};

int main() 
{
    A a1(5);
    A a2 = a1; //在定义的同时初始化使用默认复制构造函数，而不是赋值运算符

    //成员变量只有基本数据类型，因此可以使用浅拷贝
    a1.print();
    a2.print();

    return 0; 
}