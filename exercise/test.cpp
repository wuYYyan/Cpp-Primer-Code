// GDB≤‚ ‘
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    
    int a = 0, b = 10;
    cout << "a = " << a << endl;

    a += b;
    cout << "a = " << a << endl;

    int i = 1;
    int &j = i;
    int &k = j;
}
