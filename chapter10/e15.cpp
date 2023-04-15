#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    auto sum = [a](int b) {return a + b;};
    cout << sum(20) << endl; 

    return 0;
}