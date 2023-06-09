#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    private:
        string *ps;
        int i;
    public:
        HasPtr(const string &s = string(), int n = 0) : ps(new string(s)), i(n) { }
        HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) { }
        HasPtr &operator=(HasPtr hp);
        ~HasPtr() {delete ps;}
        friend void swap(HasPtr &lhp, HasPtr &rhp);
        void show() const 
        {
            cout << *ps << " " << i << endl;
        }
};

inline void swap(HasPtr &lhp, HasPtr &rhp)
{
    using std::swap;
    swap(lhp.ps, rhp.ps);
    swap(lhp.i, rhp.i);
    cout << "swap class object" << endl;
}

HasPtr &HasPtr::operator=(HasPtr hp)
{
    swap(*this, hp);
    return *this;
}

int main()
{
    HasPtr hp1("Hello World", 1);
    HasPtr hp2("Good morning", 2);
    
    swap(hp1, hp2);
    hp1.show();
    hp2.show();

    return 0;
}