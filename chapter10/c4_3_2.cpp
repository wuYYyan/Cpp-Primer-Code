#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto rit = find(v.rbegin(), v.rend(), 5);
    cout << *rit << endl;

    vector<int>::iterator it(rit.base());
    cout << *it << endl;

    return 0;
}