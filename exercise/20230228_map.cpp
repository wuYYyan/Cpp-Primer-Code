#include <map> // 包含了 map 与 multimap
#include <iostream>

using namespace std;

int main()
{
    map<string, int> mp; //map 与 multimap 的区别同 set 与 multiset 的区别，即 map 中不允许有重复的 key 出现，且以最后一次操作的 value 为主
    // key 的类型为 string， value 的类型为 int， 因此也可以支持容器嵌套
    // unordered_map 与 map 的区别在于其中的序列不是有序的，因此增删改查的时间复杂度都是O(1)

    mp.insert({"wy", 666}); //必须以列表形式整体插入
    mp["ly"] = 520; //像数组一样直接通过 key 查找 value
    mp["hello"] = 1314;
    cout << mp.size() << endl; // 3
    //当查询 map 中不存在的 key 时，int 类型的 value 默认值为0，并且会将其插入 map 中
    cout << mp["aa"] << endl; // 0

    //使用迭代器进行遍历，说明 map 维护的是递增序列，按照第一关键字的字典序进行排序
    for (auto i = mp.begin(); i != mp.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    cout << endl;

    mp["hello"] = 666; //对于相同 key 的输入，以最后一次的 value 为主，并且允许有相同 value 存在
    for (auto i = mp.begin(); i != mp.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    cout << endl;

    mp.erase(mp.find("hello")); //输入迭代器进行删除
    cout << mp.size() << endl; // 2
    mp.erase("wy"); //输入 key 进行删除
    cout << mp.size() << endl; // 1

    //map支持比较运算符，按照第一关键字的顺序、字典序规则进行比较
    map<string, int> mp1, mp2;
    mp1.insert({"ky", 520});
    mp2.insert({"ly", 521});
    if (mp > mp1)
        puts("mp > mp1"); // mp > mp1
    else
        puts("mp <= mp1"); 
    if (mp > mp2)
        puts("mp > mp2"); 
    else
        puts("mp <= mp2"); // mp <= mp2

    mp.clear();
    if (mp.empty())
        puts("此时mp为空"); // 此时mp为空
    else
        puts("此时mp不为空");

    return 0;
}