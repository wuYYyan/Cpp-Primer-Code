#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename T1, typename T2>
T1 find(T1 first, T1 last, const T2& value)
{
    for (T1 p = first; p != last; ++p)
        if (*p == value)
            return p;
    return last;
}

int main()
{
    vector<int> v = {0, 2, 4, 6, 8, 10};
    list<string> l = {"hello", "world", "!"};

    auto it1 = find(v.begin(), v.end(), 6);
    if (it1 != v.end())
        cout << *it1 << endl;
    else
        cout << "can't find 6" << endl;

    auto it2 = find(l.begin(), l.end(), "world");
    if (it2 != l.end())
        cout << *it2 << endl;
    else
        cout << "can't find \"world\"" << endl;

    return 0;
}