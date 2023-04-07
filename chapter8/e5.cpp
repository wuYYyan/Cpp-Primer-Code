#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream ifs("e4.txt");
    if(!ifs)
    {
        cerr << "Failed to open the file!" << endl;
        return -1;
    }

    string word;
    vector<string> txt;
    while(ifs >> word)
    {
        txt.push_back(word);
    }
    ifs.close();

    for(auto ch : txt)
        cout << ch << endl;   

    return 0;
}