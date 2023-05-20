#include <iostream>

using namespace std;

class HasPtr
{
    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
        HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) { }
        HasPtr &operator=(const HasPtr &hp)
        {
            if (this == &hp) //通过地址检测自赋值情况
                return *this;
            delete ps; //释放原对象旧的内存空间
            string *new_ps = new string(*hp.ps); //开辟新的内存空间
            ps = new_ps;
            i = hp.i;
            return *this;
        }
    private:
        string *ps;
        int i;
};

int main()
{
    return 0;
}