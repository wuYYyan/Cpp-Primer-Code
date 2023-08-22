#include <iostream>

using namespace std;

int main()
{
    int a = 10, b = 20;

    // 按位异或运算：相同为0，相异为1
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << a << " " << b << endl;

    return 0;
}