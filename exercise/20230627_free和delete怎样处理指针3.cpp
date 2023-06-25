#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int *p = new int(1);
    cout << *p << endl;
    free(p);
    cout << *p << endl;

    char *q = new char[100];
    strcpy(q, "wuyan");
    cout << "q = " << q << endl;
    free(q);
    cout << "q = " << q << endl;

    return 0;
}