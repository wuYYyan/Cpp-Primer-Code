#include <iostream>
using namespace std;
 
class Empty_one //生成1字节的占位符
{
    
};

class Empty_two //生成1字节的占位符
{

};

class Empty_three  //指向虚函数的指针，8字节
{
    virtual void fun() = 0;
};

// 继承其父类Empty_three的虚指针，8字节，同时取消占位符
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