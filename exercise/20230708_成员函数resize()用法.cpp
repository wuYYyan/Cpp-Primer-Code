#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(5, 2);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;

    v.resize(8);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;

    v.resize(10, -1);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;

    // resize() 只会改变容器中有效元素的数量，并不会回退内存，这一点要特别注意
    v.resize(5);
    for (auto &x : v)
        cout << x << ' ';
    cout << endl;
    cout << v.size() << " " << v.capacity() << endl;

    v.resize(0);
    cout << v.size() << " " << v.capacity() << endl;

    return 0;
}