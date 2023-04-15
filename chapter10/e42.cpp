#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

void eliDups(list<string> &words);

int main()
{
    list<string> l;

    string word;
    while(cin >> word)
        l.push_back(word);

    eliDups(l);

    return 0;
}

void eliDups(list<string> &words)
{
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;

    words.sort();
    words.unique();
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;
}