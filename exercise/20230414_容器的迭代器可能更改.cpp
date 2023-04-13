#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto it = v.begin();
    while(it != v.end())
        if(*it % 2 != 0)
        {
            it = v.insert(it, *it); //注意每次要更新迭代器
            it++, it++;
        }
        else
            it = v.erase(it);
    
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;

    return 0;
}