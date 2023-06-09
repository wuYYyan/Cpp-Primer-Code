#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo
{
    public:
        Foo sorted() &&;
        Foo sorted() const &;
    private:
        vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "right ref version" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "left ref version" << endl;
    // Foo ret(*this);
    // return ret.sorted();
    return Foo(*this).sorted();
}

int main()
{
    return 0;
}