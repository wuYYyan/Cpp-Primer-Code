#include <string>
#include <iostream>

using namespace std;

void replace_str(string &s, const string &s1, const string &s2);

int main()
{
    string str = "tho"; //目标：tho -> though
    cout << 1 << endl;

    replace_str(str, "tho", "though");
    cout << str << endl;

    return 0;
}

void replace_str(string &s, const string &s1, const string &s2)
{
    auto iter = s.begin(); //保留目标字符串的起始位置

    while(iter < s.end())
    {
        auto iter1 = iter;
        auto iter2 = s1.begin();
        while(*iter2 == *iter1 && iter2 != s1.end()) //s1是s的一部分，所以肯定是先到达末尾
        {
            iter1++, iter2++;
        }
        if(iter2 == s1.end()) //找到了要替换的目标子序列
        {
            iter = s.erase(iter, iter1); //左闭右开的迭代器区间
            auto iter3 = s2.end(); //从后向前插入
            do
            {
                iter3--;
                iter = s.insert(iter, *iter3);
            }while(iter3 > s2.begin());
            iter += s2.size(); //跳过新插入的字符串，寻找是否还有下一个目标子序列
        }
        else //从下一个字符开始重新比较目标子序列
            iter++;
    }
}