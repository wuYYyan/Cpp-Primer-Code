#include "foo.h"
#include <iostream>

using namespace std;

int main() {
    cout << Foo<int>::max(1, 2) << endl;
    cout << Foo<double>::max(1.1, 2.2) << endl;
    return 0;
}