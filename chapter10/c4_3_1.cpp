#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto it = find(v.begin(), v.end(), 5);
    cout << *it << endl;

    vector<int>::reverse_iterator rit(it);
    cout << *rit << endl;

    return 0;
}