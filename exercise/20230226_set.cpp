#include <set> // 包含了 set 与 multiset
#include <iostream>

using namespace std;

int main()
{
    // set 也是基于哈希表实现的，但是使用 set 容器存储的各个键值对，要求 key 和 value 必须相等
    set<int> s;       //不允许有重复元素，如果插入重复元素，操作将被忽略；利用这一点可以进行去重
    multiset<int> ms; //允许有重复元素

    //插入元素
    s.insert(2);
    s.insert(4);
    s.insert(1);
    s.insert(3);
    cout << s.size() << endl; // 4

    //使用迭代器进行遍历，说明 set 维护的是递增序列
    for (auto i = s.begin(); i != s.end(); i ++)
        cout << *i << ' '; // 1 2 3 4
    cout << endl;

    s.insert(3); //忽略插入相同元素的操作
    cout << s.size() << endl; // 4

    //查找元素，若该元素存在则返回指向该元素的迭代器，若该元素不存在则返回 set 中最后一个元素的迭代器
    cout << *s.find(2) << endl; // 2
    cout << *s.find(5) << endl; // 4

    cout << s.count(4) << endl; //返回元素出现的次数，因为 set 不允许有重复元素，因此返回值只能是0或1

    s.erase(4);
    cout << s.count(4) << endl;
    s.erase(s.begin()); //也可以输入迭代器
    for (auto i = s.begin(); i != s.end(); i ++)
        cout << *i << ' ';
    cout << endl;

    s.clear();
    if (s.empty())
        puts("此时s为空");
    else
        puts("此时s不为空");

    return 0;
}