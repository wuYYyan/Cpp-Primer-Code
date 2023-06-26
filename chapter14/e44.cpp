#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

map<string, function<int (int, int)>> binops = 
{
    {"+", plus<int>()},
    {"-", minus<int>()},
    {"*", multiplies<int>()},
    {"/", divides<int>()},
    {"%", modulus<int>()}
};

int main()
{
    int a, b;
    cin >> a >> b;

    cout << binops["+"](a, b) << endl;
    cout << binops["-"](a, b) << endl;
    cout << binops["*"](a, b) << endl;
    cout << binops["/"](a, b) << endl;
    cout << binops["%"](a, b) << endl;

    return 0;
}