#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto n = count_if(v.begin(), v.end(), [](const string &s) {return s.size() >= 6;});
    cout << n << endl;

    return 0;
}