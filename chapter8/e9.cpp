#include <iostream>
#include <sstream>
#include <string>

using namespace std;

istream &func(istream &in);

int main()
{
    istringstream iss("Hello world");
    func(iss);
    return 0;
}

istream &func(istream &in)
{
    string str;
    while(in >> str)
    {
        cout << str << endl;
    }
    in.clear();

    return in;
}