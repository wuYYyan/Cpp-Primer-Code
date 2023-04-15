#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void eliDups(vector<string> &words);
void biggies(vector<string> &words, vector<string>::size_type sz);

int main()
{
    vector<string> v = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(v, 4);

    return 0;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    eliDups(words); //按照字典序排序并去重
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {return s1.size() < s2.size();}); //按照长度排序并保持字典序不变
    auto wc = find_if(words.begin(), words.end(), [sz](const string &s) {return s.size() >= sz;}); //找到第一个长度大于等于目标长度的元素
    auto count = words.end() - wc; //使用迭代器的减法进行计数
    cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s) {cout << s << " ";}); //为了使用lambda表达式，必须使用for_each而不是使用范围for语句
    cout << endl;
}

void eliDups(vector<string> &words)
{
    for_each(words.begin(), words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;

    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;
}