#include <iostream>

using namespace std;

int main()
{
    int* q1 = nullptr;
    int* const q2 = nullptr;
    cout << typeid(q1).name() << endl;
    cout << typeid(q2).name() << endl;
    // const����ұ�û��ָ��*�Ļ���const�ǲ������������͵�

    int a = 10;
    int* p1 = &a;
    const int* p2 = &a;
    int* const p3 = &a; //ע��p3��������int*��������int* const
    int *p4 = p3; //�Ϸ�����Ϊp3��������int*������const��������������

    return 0;
}