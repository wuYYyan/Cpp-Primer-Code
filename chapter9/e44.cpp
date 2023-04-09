#include <string>
#include <iostream>

using namespace std;

void replace_str(string &s, const string &s1, const string &s2);

int main()
{
    string str = "tho"; //目标：tho -> though

    replace_str(str, "tho", "though");
    cout << str << endl;

    return 0;
}

void replace_str(string &s, const string &s1, const string &s2)
{
    auto pos = s.find(s1); //返回子序列出现的位置
    s.replace(pos, s1.size(), s2);
}