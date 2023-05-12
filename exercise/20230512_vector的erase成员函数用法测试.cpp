#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    cout << v[1] << ' ' << v[2] << ' ' << v[3] << endl;
    cout << &v[1] << ' ' << &v[2] << ' ' << &v[3] << endl;

    v.erase(v.begin() + 2);

    cout << v[1] << ' ' << v[2] << ' ' << v[3] << endl; 
    cout << &v[1] << ' ' << &v[2] << ' ' << &v[3] << endl;

    return 0;
}
