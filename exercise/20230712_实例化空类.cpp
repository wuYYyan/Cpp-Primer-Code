#include <iostream>

using namespace std;

class Empty
{

};

// 上述空类等价于
/*
class Empty
{
  public:
    Empty();                            //缺省构造函数
    Empty(const Empty &rhs);            //拷贝构造函数
    ~Empty();                           //析构函数 
    Empty& operator=(const Empty &rhs); //拷贝赋值运算符
    Empty* operator&();                 //取址运算符
    const Empty* operator&() const;     //取址运算符(const版本)
};
*/

int main()
{
    // 实例化一个空类的对象之后，上述六个成员函数都会被统一创建，即使什么也不做
    Empty *e = new Empty();    //缺省构造函数
    delete e;                  //析构函数
    Empty e1;                  //缺省构造函数                               
    Empty e2(e1);              //拷贝构造函数
    e2 = e1;                   //拷贝赋值运算符
    Empty *pe1 = &e1;          //取址运算符(非const)
    const Empty *pe2 = &e2;    //取址运算符(const)

    return 0;
}

// 缺省成员函数的具体实现如下：
/*
inline Empty::Empty()                          //缺省构造函数
{
}

inline Empty::~Empty()                         //析构函数
{
}

inline Empty *Empty::operator&()               //取址运算符(非const)
{
    return this; 
}

inline const Empty *Empty::operator&() const    //取址运算符(const)
{
    return this;
}

inline Empty::Empty(const Empty &rhs)           //拷贝构造函数
{
    // 对类的非静态数据成员进行以"成员为单位"逐一拷贝构造
    // 固定类型的对象拷贝构造是从源对象到目标对象的"逐位"拷贝
}
 
inline Empty& Empty::operator=(const Empty &rhs) //赋值运算符
{
    // 对类的非静态数据成员进行以"成员为单位"逐一赋值
    // 固定类型的对象赋值是从源对象到目标对象的"逐位"赋值。
}
*/