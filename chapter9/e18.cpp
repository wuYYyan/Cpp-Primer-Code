#include <string>
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<string> sd;

    string word;
    while(cin >> word)
        sd.push_back(word);

    for(const auto &r : sd)
        cout << r << " ";
    cout << endl;

    return 0;
}