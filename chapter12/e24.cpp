#include <iostream>

using namespace std;

int main()
{
    char *p = new char[10];
    char ch;
    int i = 0;

    while((ch = cin.get()) != '\n')
    {
        p[i ++] = ch;
        if(i == 10)
        {
            cout << "The length of the string is too long!" << endl;
            break;
        }
    }
    cout << p << endl;
    delete [] p;

    return 0;
}