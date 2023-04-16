#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main()
{
    map<string, int> word_count;
    set<string> exclude = {"the", "but", "and", "or", "an", "a",
                           "The", "But", "And", "Or", "An", "A"};

    string word;
    while(cin >> word)
    {
        auto ret = word_count.insert({word, 1});
        pair<map<string, int>::iterator, bool> ret = word_count.insert({word, 1});
        if(!ret.second)
            ++ret.first->second;
    }

    for(const auto &r : word_count)
        cout << r.first << "occurs " << r.second
             << ((r.second > 1) ? " times" : " time") << endl;
}