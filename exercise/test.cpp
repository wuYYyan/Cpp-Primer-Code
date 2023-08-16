// GDB
#include <iostream>

using namespace std;

int main()
{
    int *p1;
    
    int m[5][5] = {{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}};
    int (*p2)[5] = m + 3;
    return 0;
}
