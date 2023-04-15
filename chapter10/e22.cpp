#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

bool check_size(const string &str, string::size_type sz);

int main()
{
    vector<string> v = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    //auto n = count_if(v.begin(), v.end(), [](const string &s) {return s.size() >= 6;});
    auto n = count_if(v.begin(), v.end(), bind(check_size, placeholders::_1, 5));
    cout << n << endl;

    return 0;
}

bool check_size(const string &str, string::size_type sz)
{
    return str.size() <= sz;
}