#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //实现冒泡排序
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto it = v.begin(); it != v.end(); it++)
        for(auto it2 = it + 1; it2 != v.end(); it2++)
            if(*it > *it2)
                swap(*it, *it2);

    //实现选择排序
    for(auto it = v.begin(); it != v.end(); it++)
    {
        auto min = it;
        for(auto it2 = it + 1; it2 != v.end(); it2++)
            if(*min > *it2)
                min = it2;
        swap(*it, *min);
    }

    //实现插入排序
    for(auto it = v.begin(); it != v.end(); it++)
    {
        auto it2 = it;
        while(it2 != v.begin() && *it2 < *(it2 - 1))
        {
            swap(*it2, *(it2 - 1));
            it2--;
        }
    }
    return 0;
}