#include <iostream>

using namespace std;

int main()
{
    int i = 5;

    int x1 = ++i;
    cout << i << " " << x1 << endl; // 6 6

    // cout << i << endl;
    int x2 = (++i) + (++i);
    cout << i << " " << x2 << endl; // 8 16
    
    // int x3 = (++i) + (++i) + (++i); // 11 31
    int x3 = (++i) + (++i) + (i++); // 11 30
    cout << i << " " << x3 << endl;

    return 0;
}