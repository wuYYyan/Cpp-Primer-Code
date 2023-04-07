#include <iostream>
#include <vector>

using namespace std;

int func1(int a, int b);
int func2(int a, int b);
int func3(int a, int b);
int func4(int a, int b);

int main()
{
    vector<int (*)(int, int)> v1{func1, func2, func3, func4};
    //vector<decltype(func1) *> v2;

    for(auto beg = v1.begin(); beg != v1.end(); beg++)
        cout << (*beg)(10, 2) << endl;
    /*
    for(auto fp : v1)
        cout << fp(10, 2) << endl;
    */

    return 0;
}

int func1(int a, int b)
{
    return a + b;
}

int func2(int a, int b)
{
    return a - b;
}

int func3(int a, int b)
{
    return a * b;
}

int func4(int a, int b)
{
    return a / b;
}