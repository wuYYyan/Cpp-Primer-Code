#include <iostream>

using namespace std;

class numbered
{
    private:
        static int id;
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
    f(a); //按值传递参数调用合成拷贝构造函数，下同
    f(b);
    f(c);

    return 0;
}