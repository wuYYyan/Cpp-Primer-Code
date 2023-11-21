#include <iostream>

using namespace std;

const int a = 3; // 既可以是编译时常量，又可以是运行时常量
constexpr int b = 5; // 一定是编译时常量

int main()
{
    // 都可以作为数组的大小定义数组
    int arr1[a] = {0};
    int arr2[b] = {0};

    for (const auto &x : arr1)
        cout << x << " ";
    cout << endl;

    for (const auto &x : arr2)
        cout << x << " ";
    cout << endl;

    const int c = rand();
    cout << c << endl;

    // constexpr int d = rand();
    // error: the value of 'd' is not usable in a constant expression
    // cout << d << endl; 

    return 0;
}