#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

int main()
{
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = lst.begin();
    while(it != lst.end())
        if(*it %2 != 0)
            it = lst.erase(it);
        else
            it ++;
    for(const auto &r : lst)
        cout << r << " ";
    cout << endl;

    forward_list<int> fl = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pre = fl.before_begin();
    auto cur = fl.begin();
    while(cur != fl.end())
        if(*cur % 2 != 0)
            cur = fl.erase_after(pre); 
            // forward_list提供insert_after、emplace_after、erase_after成员函数，都在迭代器所指的位置之后进行相应操作
        else
            pre = cur, cur ++;
    for(const auto &r : fl)
        cout << r << " ";
    cout << endl;

    return 0;
}