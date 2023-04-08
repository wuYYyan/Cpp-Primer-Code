#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> svec;
    string word;
    auto iter = svec.begin();
    while(cin >> word)
        iter = svec.insert(iter, word);

    for(const auto &r : svec)
        cout << r << " ";
    cout << endl;

    return 0;
}