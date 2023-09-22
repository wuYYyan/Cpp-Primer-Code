#include <iostream>
#include <sstream>
#include <vector>
#include <string>
// #include <bits/stdc++.h> // 万能头文件

/*
char op[N];
scanf("%s", op + 1); // %s后面别加\n，数组名本身就是指针，不再加取地址符
*/

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(string nums) {

}

string format(string nums) {

}

using namespace std;

int main()
{
    string line, word;
    vector<PersonInfo> people;
    while (getline(cin, line)) {
        PersonInfo info;
        istringstream record(line); // 将字符串流绑定到了字符串上
        record >> info.name; // 像使用cin一样使用record
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        // 用上述方法也可以提取由空格分割的单词组成的句子
    }

    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) // 判断字符串格式是否有效
                badNums << " " << nums; // 像使用cout一样使用badNums
            else
                formatted << " " << format(nums); // 像使用cout一样使用formatted
        }
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
    }

    return 0;
}