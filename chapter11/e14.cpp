#include <map>
#include <vector>
#include <iostream>

using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &s);
void add_child(map<string, vector<pair<string, string>>> &families, const string &s1, const string &s2, const string &s3);

int main()
{
    map<string, vector<pair<string, string>>> families;

    add_family(families, "li"); 
    add_child(families, "li", "li1", "2000-1-1");
    add_child(families, "li", "li2", "2000-1-2");

    for(const auto &r : families)
    {
        cout << r.first << " family: ";
        for(const auto &r1 : r.second)
            cout << r1.first << ": " << r1.second << " ";
        cout << endl;
    }
        
    return 0;
}

void add_family(map<string, vector<pair<string, string>>> &families, const string &s)
{
    if(families.find(s) == families.end())
        families[s] = vector<pair<string, string>>();
    else 
    {
        cout << "The family is already in the map." << endl;
    }
}

void add_child(map<string, vector<pair<string, string>>> &families, const string &s1, const string &s2, const string &s3)
{
    families[s1].push_back(make_pair(s2, s3));
}