// ������к���const��Ա������������͵ĺϳ�Ĭ�Ϲ��캯��������Ϊɾ����(= delete)
#include <iostream>

using namespace std;

int x = 1;

class A
{
    private:
        const int a; // const���͵ĳ�Ա���������治ͬ��ʵ�����������ͬ
};

class B
{
    private:
        const int a = x;
        // ��������������ֱ�ӳ�ʼ��const���͵ĳ�Ա����
        // �������и���Ķ���������Ա������ֵ��һ��
};

class C
{
    public:
        C(int a_) : a(a_) {} // �����ڹ��캯���ĳ�ʼ���б��г�ʼ��const���͵ĳ�Ա����
    private:
        const int a;
};

// const int C::a = 100;
// error���Ǿ�̬���ݳ�Ա���������ⲿ��ʼ��
// ��Ϊ��̬��Ա������������г�ʼ��ʱ��������Ҫstatic�ؼ���

int main()
{
    // const����������ʱ����ͬʱ��ʼ��
    // const int a;

    const int a1 = 100;

    cout << sizeof(int)  << endl; // 4
    cout << sizeof(a1) << endl; // 4
    cout << sizeof(A) << endl; // 4
    cout << sizeof(B) << endl; // 4
    cout << sizeof(C) << endl; // 4

    // A a; // error: use of deleted function 'A::A()'
    B b; // ok
    // C c; // error: use of deleted function 'C::C()'
    C c(1); // ok

    return 0;
}