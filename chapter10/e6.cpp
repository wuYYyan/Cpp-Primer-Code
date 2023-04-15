#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 2, 10};
    fill_n(v.begin(), v.size(), 0);

    for (const auto &r : v)
        cout << r << " ";
    cout << endl;

    return 0;
}