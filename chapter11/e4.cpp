#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

string &trans(string &str);

int main()
{
    map<string, int> word_count;
    set<string> exclude = {"the", "but", "and", "or", "an", "a",
                           "The", "But", "And", "Or", "An", "A"};

    string word;
    while(cin >> word)
    {
        if(exclude.find(word) == exclude.end())
            ++word_count[trans(word)];
    }

    for(const auto &r : word_count)
        cout << r.first << "occurs " << r.second
             << ((r.second > 1) ? " times" : " time") << endl;
}

string &trans(string &str)
{
    // 方法一
    /*
    for(auto &r : str)
    {
        if(isupper(r))
            r = tolower(r);
        else if(ispunct(r))
            r = ' ';
    }
    */

    // 方法二
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 'a' + str[i] - 'A';
        else if(str[i] == '.' || str[i] == ',')
            str.erase(i, 1);
    }

    return str;
}