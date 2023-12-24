#include <iostream>
#include <string>

using namespace std;

template <typename T, typename... Args>
void foo(const T &t, const Args&... rest) {
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) << endl;
}

int main() {
    int i = 0;
    double d = 3.14;
    string s = "hello world";

    foo(i, s, 42, d);

    return 0;
}