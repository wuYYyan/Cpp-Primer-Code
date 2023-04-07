#include <iostream>

using namespace std;

class A
{
    private:
        int len;
        int *pt;
    public:
        A(int n, int *p) : len(n) 
        {
            pt = new int;
            *pt = *p;
        }
        A(const A &s)
        {
            len = s.len;
            pt = new int;
            *pt = *s.pt;
        }
        ~A()
        {
            delete pt; //new 与 delete必须成对出现
        }

        void print()
        {
            cout << &len << ": " << len << endl;
            cout << pt << ": " << *pt << endl;
        }
};

int main() 
{
    int i = 100;
    cout << &i << ": " << i << endl;

    A a1(5, &i);
    A a2 = a1; //在定义的同时初始化使用默认复制构造函数，而不是赋值运算符

    //成员变量中含有指针，动态开辟内存空间，因此必须使用深拷贝
    a1.print();
    a2.print();

    return 0; 
}