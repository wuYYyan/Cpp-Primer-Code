#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector v = {1, 2, 3, 4, 5, 6, 7, 8, 2, 10};

    int sum = accumulate(v.cbegin(), v.cend(), 0);
    cout << "Sum of all elements in vector v is " << sum << endl;

    return 0;
}