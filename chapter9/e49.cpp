#include <iostream>
#include <string>

using namespace std;

void find_str(const string &str);

int main(int argc, char *argv[]) //注意第二个参数是指针数组，而不是指针
{
    find_str(argv[1]);

    return 0;
}

void find_str(const string &str)
{
    string::size_type pos = 0;
    string s;

    while((pos = str.find_first_not_of("bdfghijklpqty", pos)) != string::npos)
    {
        s.push_back(str[pos]);
        ++pos;
    }
    cout << s << endl;
}