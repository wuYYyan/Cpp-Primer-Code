#include <iostream>

using namespace std;

class A
{
    private:
        int x = 4;
        static int y;
};

int A::y = 5;

class B : public A
{

};

int main()
{
    cout << sizeof(int) << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    // 在内存中已继承私有成员变量，但是却不具有访问权限
    // 静态成员变量不会体现在类的内存中，自然也就不会继承

    B b;
    // cout << b.x << endl;
    
    return 0;
}