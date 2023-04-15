#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 2, 4, 4, 6, 7, 7, 9};
    list<int> l;

    unique_copy(v.begin(), v.end(), back_inserter(l)); 
    //只有将vector中重复的元素放在一起才能实现去重功能
    for(const auto &r : l)
        cout << r << " ";
    cout << endl;

    return 0;
}