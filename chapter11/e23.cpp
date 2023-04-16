#include <map>
#include <vector>
#include <iostream>

using namespace std;

void add_child(multimap<string, string> &families, const string &s1, const string &s2);

int main()
{
    multimap<string, string> families;

    add_child(families, "li", "li1");
    add_child(families, "li", "li2");

    for(const auto &r : families)
    {
        cout << r.first << " " << r.second << endl;
    }
        
    return 0;
}

void add_child(multimap<string, string> &families, const string &s1, const string &s2)
{
    families.insert({s1, s2});
}