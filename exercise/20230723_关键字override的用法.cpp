#include <iostream>

using namespace std;

class A
{
    public:
        virtual void f() const {}
};

class B : public A
{
    public:
        virtual void f() const override {} 
};

int main()
{
    return 0;
}