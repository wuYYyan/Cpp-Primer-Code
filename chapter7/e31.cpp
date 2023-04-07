#include <iostream>

using namespace std;

class Y; //前向声明

class X
{
    private:
        Y *y;
};

//Y必须在X之后才能定义X的对象
class Y
{
    private:
        X x;
};

int main()
{
    return 0;
}