#include <iostream>

using namespace std;

istream &func(istream &in);

int main()
{
    cout << "Please enter a number: " << endl;
    func(cin);
    return 0;
}

istream &func(istream &in)
{
    int n;
    while(in >> n)
    {
        cout << n << endl;
    }
    in.clear();

    return in;
}