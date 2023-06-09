#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
        bool operator<(const HasPtr &hp) { return *ps < *hp.ps;}
        ~HasPtr() {delete ps;}
        void show() const 
        {
            cout << *ps << " " << i << endl;
        }
        friend void swap(HasPtr &lhp, HasPtr &rhp);
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
    vector<HasPtr> vhp = {{"Hello world"}, {"Good morning"}, {"I love you Rick"}, {"ABC"}};
    
    for (const auto &hp : vhp)
        hp.show();

    cout << "-------------" << endl;
    
    sort(vhp.begin(), vhp.end());
    for (const auto &hp : vhp)
        hp.show();

    return 0;
}