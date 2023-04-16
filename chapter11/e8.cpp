#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> words;

    string word;
    while(cin >> word)
    {
        if(find(words.begin(), words.end(), word) != words.end())
            words.push_back(word);

    }

    cout << "The words are: " << endl;
    for(const auto &r : words)
        cout << r << " ";
    cout << endl;

    return 0;
}