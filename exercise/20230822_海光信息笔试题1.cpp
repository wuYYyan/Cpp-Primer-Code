#include <iostream>

using namespace std;

int main()
{
    int a = 10, b = 20;

    // ��λ������㣺��ͬΪ0������Ϊ1
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << a << " " << b << endl;

    return 0;
}