#include <iostream>
#include <utility>

using namespace std;

void g(int &&i, int &j) {
    cout << i << " " << j << endl;
}

template <typename F, typename T1, typename T2>
void flip(F func, T1&& t1, T2&& t2) {
    func(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main() {
    int i = 1;
    flip(g, i, 42);

    return 0;
}