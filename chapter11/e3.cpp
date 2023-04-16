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
        if(exclude.find(word) == exclude.end())
            ++word_count[word];
    }

    for(const auto &r : word_count)
        cout << r.first << "occurs " << r.second
             << ((r.second > 1) ? " times" : " time") << endl;
}