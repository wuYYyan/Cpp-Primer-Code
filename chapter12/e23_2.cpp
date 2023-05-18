#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    const string str1 = "good ";
    const string str2 = "morning";

    char *p = new char(str1.size() + str2.size() + 1);

    string str = str1 + str2;
    strcpy(p, str.c_str());

    cout << p << endl;

    delete [] p;

    return 0;
}