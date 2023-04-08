#include <list>
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    list<string> sl;

    string word;
    while(cin >> word)
        sl.push_back(word);

    for(const auto &r : sl)
        cout << r << " ";
    cout << endl;

    return 0;
}