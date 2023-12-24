#include <iostream>

using namespace std;

template <typename T>
void g(T t) {
    cout << "call g(T t)" << endl;
}

template <typename T>
void g(T *t) {
    cout << "call g(T *t)" << endl;
}

int main() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42);
    g(p);
    g(ci);
    g(p2);

    return 0;
}