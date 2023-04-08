#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec;
    list<int> list;

    /*
    for(const auto &r : ia)
    {
        vec.push_back(r);
        list.push_back(r);
    }
    */
    vec.assign(ia, ia + 11);
    list.assign(ia, ia + 11);

    auto iter1 = vec.begin();
    while(iter1 != vec.end())
    {
        if(*iter1 % 2 == 0)
            iter1 = vec.erase(iter1);
        else
            iter1++;
    }

    auto iter2 = list.begin();
    while(iter2 != list.end())
    {
        if(*iter2 % 2 != 0)
            iter2 = list.erase(iter2);
        else
            iter2++;
    }

    for(const auto &r : vec)
        cout << r << " ";
    cout << endl;

    for(const auto &r : list)
        cout << r << " ";
    cout << endl;

    return 0;
}