#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[100];
    int n = strlen(str);
    gets(str);

    for (int i = 0, j = 0; i < n; i ++)
    {
        while (j < n && str[j] != ' ')
        {
            j ++;
        }
        for (int k = i; i < j; i ++)
        {
            cout << str[k];
        }
        cout << endl;
        i = j;
    }

    return 0;
}