#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
    // decltype只进行类型推断并不计算实际值
}

int main() {
    return 0;
}