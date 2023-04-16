#include <map>
#include <vector>
#include <iostream>

using namespace std;

void add_family(map<string, vector<string>> &families, const string &s);
void add_child(map<string, vector<string>> &families, const string &s1, const string &s2);

int main()
{
    map<string, vector<string>> families;

    add_family(families, "li"); 
    add_child(families, "li", "li1");
    add_child(families, "li", "li2");

    for(const auto &r : families)
    {
        cout << r.first << " has " << r.second.size() << " children." << endl;
        for(const auto &r1 : r.second)
            cout << r1 << " ";
        cout << endl;
    }
        
    return 0;
}

void add_family(map<string, vector<string>> &families, const string &s)
{
    if(families.find(s) == families.end())
        families[s] = vector<string>();
    else 
    {
        cout << "The family is already in the map." << endl;
    }
}

void add_child(map<string, vector<string>> &families, const string &s1, const string &s2)
{
    families[s1].push_back(s2);
}