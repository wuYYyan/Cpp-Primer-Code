#include <iostream>

using namespace std;

const int a = 3; // �ȿ����Ǳ���ʱ�������ֿ���������ʱ����
constexpr int b = 5; // һ���Ǳ���ʱ����

int main()
{
    // ��������Ϊ����Ĵ�С��������
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