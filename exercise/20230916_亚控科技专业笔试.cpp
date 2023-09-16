#include <iostream>

using namespace std;

int main()
{
    int i = 5;

    int x1 = ++i;
    cout << i << " " << x1 << endl;

    int x2 = (++i) + (++i);
    cout << i << " " << x2 << endl;
    
    int x3 = (++i) + (++i) + (++i);
    cout << i << " " << x3 << endl;

    return 0;
}