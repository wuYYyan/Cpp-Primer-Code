#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec1 = {1, 2, 3, 4, 5};
    vector<int> ivec2 = {1, 2, 3, 4, 5, 6};
    vector<int> ivec3 = {2, 2, 3, 4, 5};

    cout << (ivec1 < ivec2) << endl; //true
    cout << (ivec1 < ivec3) << endl; //true
    
    return 0;
}