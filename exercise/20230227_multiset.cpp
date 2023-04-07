#include <set> // 包含了 set 与 multiset
#include <iostream>

using namespace std;

int main()
{
    multiset<int> ms; //允许有重复元素出现

    //插入元素
    ms.insert(2);
    ms.insert(4);
    ms.insert(1);
    ms.insert(3);
    cout << ms.size() << endl; // 4

    //使用迭代器进行遍历，说明 multiset 维护的是递增序列
    for (auto i = ms.begin(); i != ms.end(); i ++)
        cout << *i << ' '; // 1 2 3 4
    cout << endl;
    //库函数 end 返回指向容器最后一个元素(注意，是已排好序的最后一个)所在位置后一个位置的双向迭代器

    ms.insert(3); //允许插入相同元素的操作
    cout << ms.size() << endl; // 5

    //查找元素，若该元素存在则返回指向该元素的迭代器，若该元素不存在则返回 set 中最后一个元素的迭代器
    cout << *ms.find(2) << endl; // 2
    cout << *ms.find(100) << endl; // 5

    cout << ms.count(3) << endl; //返回元素出现的次数，因为允许有重复元素，因此可以是任何非负整数

    //返回一个指向当前 multiset 容器中第一个大于或等于 val 的元素的迭代器
    cout << *ms.lower_bound(2) << endl;
    //返回一个指向当前 multiset 容器中第一个大于 val 的元素的迭代器
    cout << *ms.upper_bound(2) << endl;

    ms.erase(3); //将删除所有值为3的节点，对于 multiset，因为允许有重复元素，这一操作可能删掉多个节点
    ms.erase(ms.begin()); //也可以输入迭代器
    for (auto i = ms.begin(); i != ms.end(); i ++)
        cout << *i << ' ';
    cout << endl;
    
    ms.clear();
    if (ms.empty())
        puts("此时ms为空");
    else
        puts("此时ms不为空");

    return 0;
}