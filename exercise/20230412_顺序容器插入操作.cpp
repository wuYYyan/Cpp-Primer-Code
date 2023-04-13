#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

int main()
{
    list<int> l;
    for(size_t i = 0; i != 4; i ++) //size_t类型，是与机器相关的无符号整数类型
        l.push_front(i); //在头部插入
    for(const auto &r : l)
        cout << r << " ";
    cout << endl;

    vector<int> v;
    for(size_t i = 0; i != 4; i ++)
        v.push_back(i); //vector并不存在push_front
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;

    //使用insert与begin实现类似于push_front的功能
    int n = 3;
    while(n--)
        v.insert(v.begin(), 5); //在给定的迭代器之前插入元素
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;

    v.insert(v.end(), 6, 6);
    for(const auto &r : v)
        cout << r << " ";
    cout << endl;

    list<string> sl = {"hello", "world", "good"};
    sl.push_front("morning");
    auto iter = sl.begin();
    string word;
    while(cin >> word)
        iter = sl.insert(iter, word); //返回指向插入元素的迭代器
    for(const auto &r : sl)
        cout << r << " ";
    cout << endl;


    return 0;
}