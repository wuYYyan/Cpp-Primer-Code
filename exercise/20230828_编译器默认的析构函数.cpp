#include <iostream>

using namespace std;

struct A1
{

};

struct A2
{
    A2(); // ���캯��
    A2(const A2& a2); // �������캯��
    ~A2(); // ��������
    A2& operator=(const A2& a2); // �������������
    A2* operator&(); // ȡַ�����
    const A2* operator&() const; // ȡַ�����(const�汾)
};

struct A3
{
    A3(); // ���캯��
    A3(const A3& a2); // �������캯��
    virtual ~A3(); // ��������
    A3& operator=(const A3& a2); // �������������
    A3* operator&(); // ȡַ�����
    const A3* operator&() const; // ȡַ�����(const�汾)
};

int main()
{
    cout << sizeof(A1) << endl; // 1
    cout << sizeof(A2) << endl; // 1
    cout << sizeof(A3) << endl; // 8
    // �����Ϊʲôcpp���ὫĬ�ϵ�������������Ϊ�麯����ԭ��

    return 0;
}