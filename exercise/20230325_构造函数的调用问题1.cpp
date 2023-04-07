#include <iostream>
#include <cstring>

using namespace std;

class Name
{
    char name[20];
    public:
        Name() //默认构造函数
        {
            strcpy(name, " ");
            cout << '?';
        }
        Name(const char *fname)
        {
            strcpy(name, fname);
            cout << '?';
        }
        void show()
        {

        }
};

int main()
{
    Name names[3] = {Name{"Rick"}, Name{"Jack"}}; 
    //最终将输出三个'?'，因为数组中的最后一个元素将执行默认初始化
    //前两个元素通过【显式地】调用构造函数执行初始化
    return 0;
}