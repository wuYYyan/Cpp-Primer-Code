#include <iostream>

using namespace std;

int main() {
    int a = 1; // ��ֵ��ʾ��
    int b(2); // ������ʾ��
    int c {3}; // ��ʼ���б�
    cout << a << " " << b << " " << c << endl;

    int a1 = 1.5;
    int b1 = 2.4;
    int c1 {3.5}; // ������խת�����������
    cout << a1 << " " << b1 << " " << c1 << endl;

    return 0;
}