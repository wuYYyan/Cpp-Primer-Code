#include <cassert>
#include <iostream>

using namespace std;

int main()
{
    int n1, n2;

    cout << "Please enter two numbers: " << endl;
    cin >> n1 >> n2;

    assert(n2 != 0);

    cout << "n1 / n2 = " << n1 / n2 << endl;

    return 0;
}