#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void g(T&& val) {
    vector<T> v; // �޷�����һ���洢���õ���������Ϊ���ñ����Ƕ���
}

int main() {
    int x = 1;
    // g(x);
    g(42);
    return 0;
}