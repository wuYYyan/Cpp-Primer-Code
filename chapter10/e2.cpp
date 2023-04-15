#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main()
{
    list<string> l = {"abc", "def", "ghi", "abc", "mno", "ghi", "stu", "vwx", "xyz"};

    string str;
    cout << "Please enter a string you want to find: ";
    cin >> str;

    cout << "List l contains " << count(l.cbegin(), l.cend(), str) << " " << "times of " << str << endl;

    return 0;
}