#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void print(const T& t)
{
    for (typename T::size_type i = 0; i < t.size(); ++i)
        cout << t.at(i) << " ";
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