#include <iostream>

using namespace std;

// void func(int *p)
// {
//     cout << "func(int *p)" << endl;
// }

class A
{

};

void func(A *p)
{
    cout << "func(A *p)" << endl;
}

// void func(int p)
// {
//     cout << "func(int p)" << endl;
// }

// void func(char *p)
// {
//     cout << "func(char *p)" << endl;
// }

int main()
{
    // func(nullptr); // func(char *p)
    // nullptr������ʽת��Ϊ����ָ�����ͣ���������ָ�����ͺ��Զ������ָ������
    
    func(NULL);
    // NULL������ʽת��Ϊ����ָ���������Զ������ָ�����ͣ�Ҳ��ת��Ϊ������������

    cout << sizeof(nullptr) << endl; // 8
    cout << sizeof(NULL) << endl; // 8

    return 0;
}