#include <list>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    list<const char *> cl{"aaa", "bbb", "ccc"};
    vector<string> vec;
    vec.assign(cl.begin(), cl.end());

    for(auto &r : vec)
        cout << r << " ";
    cout << endl;

    return 0;
}