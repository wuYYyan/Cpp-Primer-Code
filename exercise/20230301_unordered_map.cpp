#include <string>
#include <iostream>
#include <unordered_map> // 包含了unordered_map 与 unordered_multimap
#include <unordered_set> // 包含了unordered_set 与 unordered_multiset

using namespace std;

int main()
{
    unordered_map<string, int> ump1, ump2;

    ump1.insert({"bb", 1});
    ump1.insert({"aa", 10});
    ump1.insert({"aa", 2});
    ump1.insert({"aa", 3}); //不允许 key 重复
    ump1.insert({"dd", 1}); //允许 value 重复

    //当 [] 运算符位于 = 右侧时，则新添加键值对的键为 [] 运算符内的元素、值为键值对要求的值类型的默认值(int 类型默认值为0)
    int x = ump1["cc"]; 
    cout << x << endl; // 0

    //当 [] 运算符位于 = 左侧时，则新添加键值对的键为 [] 运算符内的元素，其值为 = 右侧的元素。算法题中多用这种插入方式
    ump1["bd"] = 6; 
    //当哈希表中不存在要查找的 key 时，int 类型的 value 默认值为0，然后在哈希表中加入这个键值对
    cout << ump1["wy"] - 1 << endl; // -1

    cout << ump1["aa"] << endl; // 对于重复的 key 插入，以第一次操作时的 value 为准

    //使用迭代器进行遍历，说明 unordered_map 维护的是无序序列，既不按照字典序排序，也不按照插入的先后顺序排序
    // begin 返回的是第一个键值对的地址；end 返回的是最后一个键值对的下一个地址，因此可以作为终止条件
    for (auto i = ump1.begin(); i != ump1.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    cout << endl << endl;

    ump2.insert({"cc", 5});
    ump2.insert({"bc", 3});
    ump2.insert({"ab", 10});
    ump2["ca"] = 8;

    if (ump2.count("cd")) // 查询时输入的应该是 key，而不是键值对，返回出现次数
        puts("Yes");
    else
        puts("No"); 
    //这种查询方式没有就是没有，不会像 [] 查询一样，在没有的情况下自动使用 value 的默认值加入 map 中

    if (ump2["wy"]) //算法题中首次查询千万不能使用这种方式，因为查询完毕之后会导致自动插入
        puts("Yes");
    else
        puts("No");

    //使用迭代器进行遍历，说明 unordered_map 维护的是无序序列，既不按照字典序排序，也不按照插入的先后顺序排序
    for (auto i = ump2.begin(); i != ump2.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    cout << endl;

    //无序关联容器只能比较相等或不相等，不能比较大小
    if (ump1 == ump2) 
        cout << "ump1 == ump2" << endl;
    else
        cout << "ump1 != ump2" << endl; // ump1 != ump2

    unordered_set<int> s;
    s.insert(1);

    if (s.count(1))
        puts("Yes");
    else
        puts("No");

    return 0;
}