#include <iostream>
#include <string>

using namespace std;

void rename_str(string &s, const string &s1, const string &s2);

int main()
{
    string name = "Rick";
    rename_str(name, "Mr.", "Jr.");
    cout << name << endl;

    return 0;
}

void rename_str(string &s, const string &s1, const string &s2)
{
    s.insert(s.begin(), s1.begin(), s1.end());
    s.append(" ");
    s.append(s2.begin(), s2.end());
}