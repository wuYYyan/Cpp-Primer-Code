#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void print(const T& t)
{
    for (auto i = t.begin(); i != t.end(); i++)
        cout << *i << " ";
    cout << endl;
}

int main()
{
    string s = "Hello, World!";
    print(s);

    vector<int> v = {1, 2, 3, 4, 5};
    print(v);

    return 0;
}