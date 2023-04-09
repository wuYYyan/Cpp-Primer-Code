#include <string>
#include <iostream>

using namespace std;

void replace_str(string &s, const string &s1, const string &s2);

int main()
{
    string str = "abcdefgthouvwxyz";

    replace_str(str, "tho", "though");
    cout << str << endl;

    return 0;
}

void replace_str(string &s, const string &s1, const string &s2)
{
    auto iter = s.begin();

    while(iter < s.end())
    {
        auto iter1 = iter;
        auto iter2 = s1.begin();
        while(*iter2 == *iter1 && iter2 != s1.end())
        {
            iter1++, iter2++;
        }
        if(iter2 == s1.end())
        {
            iter = s.erase(iter, iter1);
            auto iter3 = s2.end();
            do
            {
                iter3--;
                iter = s.insert(iter, *iter3);
            }while(iter > s2.begin());
            iter += s2.size();
        }
        else
            iter++;
    }

    return;
}