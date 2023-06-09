#include <iostream>

using namespace std;    

class HasPtr
{
    private:
        string *ps;
        int i;
    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
        ~HasPtr() { delete ps; }
};

int main()
{
    HasPtr hp1("hello world");
    HasPtr hp2(hp1);


    return 0; 
}