#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
    // decltypeֻ���������ƶϲ�������ʵ��ֵ
}

int main() {
    return 0;
}