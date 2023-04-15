#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(auto it = v.cend(); it != v.cbegin(); )
        cout << *(--it) << " ";
    cout << endl;

    return 0;
}