#include <iostream>

using namespace std;

struct A
{

};

class B : public A
{

};

class C
{

};

struct D : private C
{

};

int main()
{
    return 0;
}