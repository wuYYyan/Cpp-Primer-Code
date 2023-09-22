// 链接：https://mp.weixin.qq.com/s/PBXKKCjD2QfDUV45ESPkPg
#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int idx = 0; // 不要使用index作为变量名，

void change(string &str) {
    for (int i = 0; i < str.size(); i ++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32; // 在ASCII码表中，相同字母的大小写偏移为32
    // 这里可以直接使用库函数toupper，改写为str[i] = toupper(str[i]);
}

bool check(char c) {
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= 'a' && c <= 'z') return true;
    return false;
}

int main()
{
    string line, word;
    getline(cin, line); // 此时getline是string库函数，它指出从cin中查找输入，内容存放到line中
    // cout << line << endl;
    while ((cin >> word) && (word != "q")) { // 本地编译器的测试，最好手动设置结束标志，否则编译器不知道什么时候输入结束
        change(word); // 由于句子中的单词对大小写不敏感，所以先将输入单词列表中的单词全部转化为大写
        // cout << word << endl;
        m[word] = idx; // 如果某个单词在单词列表中重复出现，新的索引值会将旧的索引值覆盖
        // 统一以大写作为哈希表中的键，以后在将句子中的单词替换为对应的序号之前也要先转换为大写
        idx ++;
    }
    // 按下 Ctrl + C 结束输入
    string res;
    int beg = 0;
    for (int i = 0; i < line.size(); i ++) {
        if (line[i] == '"') {
            i ++;
            while (i < line.size() && line[i] != '"') // 用双引号包含的单词不进行替换，所以有这个循环
                i ++;
        }
        while (i < line.size() && check(line[i])) // 这个判断是要跳过句子中可能出现的其他符号
            i ++;
        // 把满足替换要求的单词提取出来
        string str = line.substr(beg, i - beg); // 返回字符串line从beg开始的(i - beg)个字符的拷贝
        // cout << str << endl;
        // cout << i << endl;
        beg = i + 1;
        string str_backup = str;
        change(str); // 因为在存入哈希表之前全都变为了大写，所以查找之前也要全变成大写才可以
        if (m.find(str) != m.end()) // 不能使用 if(m[str] != 0) 来判断单词是否在所给单词列表中出现过，这样可能会丢掉索引为零的单词
            res += to_string(m[str]); // 把对应的索引值变成字符串形式，这样才能使用字符串的加法
        else
            res += str_backup; // 满足替换要求的单词在所给单词列表中并不存在，还是原样添加到res末尾
        res += line[i]; // 把可能存在的其他符号也原样搬过来
        // if (i == line.size())
        //     break;
    }
    cout << res << endl;
    return 0;
}