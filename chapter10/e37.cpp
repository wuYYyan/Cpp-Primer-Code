#include <list>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l;

    copy(v.crbegin() + 3, v.crbegin() + 8, back_inserter(l));
    for(const auto &i : l)
        cout << i << " ";
    cout << endl;

    return 0;
}