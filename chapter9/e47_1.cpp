#include <iostream>
#include <string>

using namespace std;

void find_char(const string &str, const string &s);

int main()
{
    string str = "ab2c3d7R4E6";

    find_char(str, "0123456789");
    cout << "--------------------------" << endl;
    find_char(str, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    return 0;
}

void find_char(const string &str, const string &s)
{
    string::size_type pos = 0;

    while((pos = str.find_first_of(s, pos)) != string::npos)
    {
        cout << "pos = " << pos << ", char: " << str[pos] << endl;
        pos++;
    }
}