#include <iostream>

using namespace std;

int main()
{
    // ѡ����1
    int k = 7 >> 1;
    cout << "k = " << k << endl; // k = 3

    // ѡ����2
    int j;
    int a = (j = 3, j ++); // ֻҪ��һ�����ʽ��ǰ������ͺ�������Ͳ�һ�������Ǹ����ű��ʽ
    cout << "a = " << a << endl; // a = 3

    // ѡ����3
    int arr[3] = {1, 2, 3};
    cout << arr << endl;
    cout << *arr << endl;
    cout << *(arr + 1) << endl;
    cout << arr[0] << endl;
    // cout << arr ++ << endl; // ���ʽ�����ǿ��޸ĵ���ֵ���������� const ����

    // ѡ����4
    char ch[] = "abc\0def";
    char *p = ch;
    printf("%c", *p + 4); // e
    
    return 0;
}