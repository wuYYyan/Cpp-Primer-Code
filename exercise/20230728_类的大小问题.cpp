#include <iostream>

using namespace std;

class One
{

};

class Two
{
    public:
        Two() {}
        ~Two() {}
};

class Three
{
    public:
        Three() {}
        ~Three() {}
        virtual void fun() {}
};

class Four
{
    public:
        Four() {}
        ~Four() {}
        virtual void fun() {}
        virtual void fun1() {}
};

class Five
{
    public:
        int data;
        Five() {}
        ~Five() {}
        virtual void fun() {}
};

int main()
{
    cout << "sizeof(One): " << sizeof(One) << endl; //1��ϵͳΪ��������һ�ֽڵ�ռλ��
    cout << "sizeof(Two): " << sizeof(Two) << endl; //1�����麯����������ָ��
    cout << "sizeof(Three): " << sizeof(Three) << endl; //8,ͨ����ָ��ָ����������麯��
    cout << "sizeof(Four): " << sizeof(Four) << endl; //8�������м����麯����ֻ��һ����ָ�룬�麯��������ֻ���������
    cout << "sizeof(Five): " << sizeof(Five) << endl; //16���漰���ڴ��������
    // �ͽṹ���ڴ����ĵ���һ������ָ���������������������λ�ÿ�ʼ�����ڴ�

    return 0;
}