#include <iostream>

using namespace std;

class A
{
    private:
        int x = 4;
        static int y;
};

int A::y = 5;

class B : public A
{

};

int main()
{
    cout << sizeof(int) << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    // ���ڴ����Ѽ̳�˽�г�Ա����������ȴ�����з���Ȩ��
    // ��̬��Ա������������������ڴ��У���ȻҲ�Ͳ���̳�

    B b;
    // cout << b.x << endl;
    
    return 0;
}