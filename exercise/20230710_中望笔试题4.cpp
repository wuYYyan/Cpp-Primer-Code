#include <iostream>

using namespace std;

int main()
{
    bool a = true, b = false, c = true;
    if (!(!(a&&b)||!c))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if ((a&&b)&&c)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if ((!(!(a&&b)||!c)) == ((a&&b)&&c))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}