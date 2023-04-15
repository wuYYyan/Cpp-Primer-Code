#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    list<int> l = {0, 2, 3, 4, 0, 6, 7, 8, 0, 10};

    auto rit = find(l.crbegin(), l.crend(), 0);
    if(rit == l.crend())
        cout << "Not found" << endl;
    else
        cout << *rit << endl;

    return 0;
}