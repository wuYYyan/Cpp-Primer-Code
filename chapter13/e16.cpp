#include <iostream>

using namespace std;

class numbered
{
    private:
        static int id; //静态数据成员变量被该类的所有对象所共享 
    public:
        int mysn;
        numbered() { mysn = id++; }
        numbered(const numbered &n) { mysn = id++; } //拷贝构造函数
        numbered &operator=(const numbered &n) { mysn = id++; } //拷贝赋值运算符
};

int numbered::id = 0; //静态成员初始化

//void f(numbered s)
void f(numbered &s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b; //b、c的初始化调用自定义拷贝构造函数
    f(a); //按引用传递参数，不会调用自定义的拷贝构造函数
    f(b);
    f(c);

    return 0;
}