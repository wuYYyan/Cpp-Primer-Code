// ������к����������͵ĳ�Ա������������͵ĺϳ�Ĭ�Ϲ��캯��������Ϊɾ����
#include <iostream>

using namespace std;

int x = 1;

class A
{
    private:
        int &r; // �������͵ĳ�Ա�����ڹ��캯���ĳ�ʼ���б��н��г�ʼ��
};

class B
{
    private:
        int &r = x; // ������������ʱΪ���ó�Ա�����ṩ��ʼֵ
};

class C
{
    private:
        // int &r = 1; // error���޷�����ֵ���ð󶨵���ֵ(����ֵ����)��
};

int main()
{
    // �������͵ı���������ʱ����ͬʱ��ʼ��
    // int &r;

    int &r1 = x;

    cout << sizeof(int)  << endl; // 4
    cout << sizeof(r1) << endl; // 4
    cout << sizeof(A) << endl; // 8(why?)
    cout << sizeof(B) << endl; // 8(why?)
    cout << sizeof(C) << endl; // 1

    // A a; // error: use of deleted function 'A::A()'
    B b; // ok

    return 0;
}