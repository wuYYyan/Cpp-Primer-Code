#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void g(T&& val) {
    vector<T> v; // 无法创建一个存储引用的容器，因为引用本身不是对象
}

int main() {
    int x = 1;
    // g(x);
    g(42);
    return 0;
}