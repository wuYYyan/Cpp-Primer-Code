#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    multimap<string, int> mmp;

    mmp.insert({"bb", 4});
    mmp.insert({"aa", 2});
    mmp.insert({"aa", 1});
    mmp.insert({"aa", 3});

    //使用迭代器进行遍历，说明 multimap 维护的是递增序列，按照第一关键字的字典序进行排序
    //若第一关键字相同，则第二关键字按照插入的顺序进行排序
    for (auto i = mmp.begin(); i != mmp.end(); i ++)
        cout << i->first << ' ' << i->second << endl;
    
    //cout << mp["aa"] << endl; // 因为 multimap 中允许有重复元素出现，因此这种查询方式有可能会造成输出不唯一，所以语法不正确

    return 0;
}