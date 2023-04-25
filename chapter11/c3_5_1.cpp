#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<int> mset = {0, 1, 2, 3, 3, 3, 3, 5, 6, 7, 8, 9};

    auto it1 = mset.lower_bound(3);
    cout << *it1 << endl;

    auto it2 = mset.upper_bound(3);
    cout << *it2 << endl;

    auto it3 = mset.lower_bound(4);
    cout << *it3 << endl;

    auto it4 = mset.upper_bound(3);
    cout << *it4 << endl;
    //如果没有元素与给定关键字匹配，则lower_bound()和upper_bound()返回相等的迭代器
    //返回的迭代器都指向给定关键字的插入点，能保持容器中元素顺序的插入位置

    return 0;
}