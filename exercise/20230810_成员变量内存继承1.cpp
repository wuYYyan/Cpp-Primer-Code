#include <iostream>

using namespace std;

class A
{
    private:
        int a = 4;
};

class B : public A
{

};

int main()
{
    cout << sizeof(int) << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    // ���ڴ����Ѽ̳�˽�г�Ա����������ȴ�����з���Ȩ��

    B b;
    // cout << b.a << endl;
    
    return 0;
}