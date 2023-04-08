#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> ivec{2, 4, 6, 8, 10, 1, 3, 5, 7, 9};

    vector<int>::value_type x;
    x = 100;
    ivec[0] = x;
    cout << ivec[0] << endl;

    vector<int>::iterator it;
    it = ivec.begin();
    cout << *it << endl;

    vector<int>::reference rf = ivec[9];
    rf = 90;
    cout << rf << endl;

    return 0;
}