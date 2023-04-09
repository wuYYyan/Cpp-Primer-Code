#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec = {"123", "456", "789"};
    int sum = 0;

    for(const auto &r : vec)
        sum += stoi(r);
    cout << "Sum = " << sum << endl;

    return 0;
}