#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    auto sum = [](int a, int b) {return a + b;};
    cout << sum(1, 1) << endl;

    return 0;
}