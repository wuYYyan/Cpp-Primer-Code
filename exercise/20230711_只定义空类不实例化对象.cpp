#include <iostream>
using namespace std;
 
class Empty_one //����1�ֽڵ�ռλ��
{
    
};

class Empty_two //����1�ֽڵ�ռλ��
{

};

class Empty_three  //ָ���麯����ָ�룬8�ֽ�
{
    virtual void fun() = 0;
};

// �̳��丸��Empty_three����ָ�룬8�ֽڣ�ͬʱȡ��ռλ��
class Empty_four : public Empty_two, public Empty_three
{
};
 
int main()
{
    cout << "sizeof(Empty_one): " << sizeof(Empty_one) << endl; // 1
    cout << "sizeof(Empty_two): " << sizeof(Empty_two) << endl; // 1
    cout << "sizeof(Empty_three): " << sizeof(Empty_three) << endl; // 8
    cout << "sizeof(Empty_four): " << sizeof(Empty_four) << endl; // 8
    return 0;
}