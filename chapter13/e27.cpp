#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    private:
        string *ps;
        int i;
        size_t *use;
    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {  }
        HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
        HasPtr &operator=(const HasPtr &hp)
        {
            ++*hp.use;
            if (--*use == 0)
            {
                delete ps;
                delete use;
            }
            ps = hp.ps;
            i = hp.i;
            use = hp.use;
            return *this;
        }
        ~HasPtr()
        {
            if (--*use == 0)
            {
                delete ps;
                delete use;
            }
        }   
};

int main()
{
    return 0;
}