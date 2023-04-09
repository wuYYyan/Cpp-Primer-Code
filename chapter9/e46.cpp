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
    s.insert(0, s1);
    s.append(" ");
    s.append(s2);
}