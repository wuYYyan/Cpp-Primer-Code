#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    vector<pair<string, int>> vec;

    string str;
    int i;

    while(cin >> str && cin >> i)
    {
        vec.push_back({str, i});
    }

    for(const auto &r : vec)
        cout << r.first << ": " << r.second << endl;

    return 0;
}