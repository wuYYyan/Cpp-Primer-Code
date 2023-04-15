#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 2, 10};

    int num;
    cout << "Please enter a number you want to find: ";
    cin >> num;

    cout << "Vector v contains " << count(v.cbegin(), v.cend(), num) << " " << num << "s." << endl;

    return 0;
}