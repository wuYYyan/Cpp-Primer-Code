#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l1, l2, l3;

    // 使用back_inserter
    copy(v.begin(), v.end(), back_inserter(l1));
    for(const auto &r : l1)
        cout << r << " ";
    cout << endl;
    
    // 使用front_inserter
    copy(v.begin(), v.end(), front_inserter(l2));
    for(const auto &r : l2)
        cout << r << " ";
    cout << endl;
    
    // 使用inserter
    copy(v.begin(), v.end(), inserter(l3, l3.begin()));
    for(const auto &r : l3)
        cout << r << " ";
    cout << endl;
    
    return 0;
}