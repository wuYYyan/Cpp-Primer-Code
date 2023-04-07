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

    string line;
    vector<string> txt;
    while(getline(ifs, line))
    {
        txt.push_back(line);
    }
    ifs.close();

    for(auto ch : txt)
        cout << ch << endl;   

    return 0;
}