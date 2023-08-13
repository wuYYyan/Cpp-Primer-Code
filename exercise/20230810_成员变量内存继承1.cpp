#include <iostream>

using namespace std;

class A
{
    private:
        int a = 4;
};

class B : public A
{

};

int main()
{
    cout << sizeof(int) << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    // 在内存中已继承私有成员变量，但是却不具有访问权限

    B b;
    // cout << b.a << endl;
    
    return 0;
}