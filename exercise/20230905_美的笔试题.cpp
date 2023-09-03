#include <iostream>

using namespace std;

// void func(int *p)
// {
//     cout << "func(int *p)" << endl;
// }

void func(int p)
{
    cout << "func(int p)" << endl;
}

void func(char *p)
{
    cout << "func(char *p)" << endl;
}

int main()
{
    func(nullptr); // func(char *p)
    return 0;
}