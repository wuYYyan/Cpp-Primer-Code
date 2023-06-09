#include <iostream>

using namespace std;

class numbered
{
    private:
        static int id; //静态成员变量，不依赖于任何对象，而属于整个类
    public:
        int mysn;
        numbered() { mysn = id++; }
};

int numbered::id = 0; //静态成员初始化

void f(numbered s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b; //b、c的初始化调用合成拷贝构造函数
    // 结果是所有的对象共用一个static数据成员，因为合成拷贝构造函数只是简单的拷贝了对象的数据成员
    f(a); //按值传递参数调用合成拷贝构造函数，下同
    f(b);
    f(c);

    return 0;
}