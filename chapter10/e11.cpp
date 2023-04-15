#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void eliDups(vector<string> &words);
bool isShorter(const string &s1, const string &s2);

int main()
{
    vector<string> v = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    eliDups(v);

    return 0;
}

void eliDups(vector<string> &words)
{
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;

    sort(words.begin(), words.end());
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;

    auto end_unique = unique(words.begin(), words.end());
    cout << "The size of words is " << words.size() << endl;
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;

    words.erase(end_unique, words.end());
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;

    stable_sort(words.begin(), words.end(), isShorter);
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
