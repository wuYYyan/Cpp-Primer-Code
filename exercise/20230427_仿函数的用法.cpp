#include <iostream>
#include <string>

using namespace std;

class Hasher
{
    public:
        Hasher() {
            cout << "Hasher()" << endl;
        }
        Hasher(string str) {
            cout << "Hasher(string)" << endl;
        }
        size_t operator()(const string &str) const {
            cout << "operator=()" << endl;
            //为了使用仿函数就必须重载()运算符
        }
};

int main()
{
    Hasher h("Hello World!");
    h("Good morning!"); //像函数名一样使用类的对象
    Hasher()("Good morning!"); //创建临时的匿名对象 

    return 0;
}