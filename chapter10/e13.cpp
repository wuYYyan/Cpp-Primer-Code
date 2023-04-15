#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool more_or_equal_five(const string &s);

int main()
{
    vector<string> v = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto iter = partition(v.begin(), v.end(), more_or_equal_five);
    for(auto i = v.begin(); i != iter; ++i)
        cout << *i << " ";
    cout << endl;

    return 0;
}

bool more_or_equal_five(const string &s)
{
    return s.size() >= 5;
} 