#include <iostream>

using namespace std;

const int a = 3;
constexpr int b = 5;

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

    return 0;
}