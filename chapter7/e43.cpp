#include <iostream>

using namespace std;

class NoDefault
{
    private:
        int n;
    public:
        NoDefault(int i) : n(i) {}
};

class C
{
    private:
        NoDefault nd;
    public:
        C(int i = 100) : nd(i) {}
};

int main()
{
    return 0;
}