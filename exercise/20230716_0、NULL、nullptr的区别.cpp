#include <iostream>

using namespace std;

typedef decltype(nullptr) nullptr_t;

int fun(int) { cout << "int" << endl; }
int fun(int *) { cout << "int *" << endl; }
int fun(nullptr_t) { cout << "nullptr_t" << endl; }

int main()
{
    cout << sizeof(0) << endl; //4
    cout << sizeof(NULL) << endl; //8
    cout << sizeof(nullptr) << endl; //8

    int *p = NULL; //NULL��һ���궨�壬ֵΪ0
    // �������Ҳ����˵�������NULL��ָ�����ͣ���ô������pʱ��Ҫ��������ת��
    // Ȼ����Ҫ����ת��Ҳ���Ա���ͨ����˵��NULL��һ���궨�壬ֵΪ0(C++ 11)
    // ��C++ 11֮��NULL��nullptr�Ĵ���ֵ

    fun(0);
    // fun(NULL); //�����ж��ƥ��
    fun(nullptr);

    return 0;
}