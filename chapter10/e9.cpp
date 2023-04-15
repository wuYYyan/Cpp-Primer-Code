#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void eliDups(vector<string> &words);

int main()
{
    vector<string> v = {"abc", "def", "ghi", "abc", "mno", "ghi", "stu", "vwx", "xyz"};

    /*string word;
    while(cin >> word)
        v.push_back(word);*/

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
}