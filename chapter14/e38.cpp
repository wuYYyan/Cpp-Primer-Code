#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StrLen
{
    private:
        int n;
    public: 
        StrLen(int i = 0) : n(i) {}
        int operator()(const string &str) {
            return str.size() == n;
        }
};

int main()
{
    ifstream ifs("e38.txt");
    vector<string> svec;

    string str;
    while (ifs >> str)
    {
        svec.push_back(str);
    }

    for (int i = 1; i <= 10; i ++)
        std::cout << count_if(svec.begin(), svec.end(), StrLen(i)) << ' ';
    std::cout << endl;

    return 0;
}