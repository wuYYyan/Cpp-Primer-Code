//C++ Primer P250，练习7.31
//定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象
#include <iostream>

using namespace std;

class Y; //前向声明，在Y定义之前为不完全类型
//不完全类型只能定义指向这种类型的指针或引用，因为指针本身所占内存大小与数据成员无关
//也只能声明(但不能定义)以该类型为参数或返回类型的函数

class X
{
    private:
        Y *y; //不完全类型
        X *x; //类允许包含指向它自身类型的引用或指针
        static X staticX; //静态数据成员可以是它所属的类型
    public:
        Y example(); //只能声明以不完全类型作为参数或返回类型的函数
};

//Y必须在X之后才能定义X的对象
class Y
{
    private:
        X x; //类X已经被定义，因此可以包含其对象
        Y *y; //类允许包含指向它自身类型的引用或指针
        static Y staticY; //静态数据成员可以是它所属的类型
};

Y X::example() //类Y已经被定义，此时可以给出函数的完整定义
{

}

int main()
{
    return 0;
}