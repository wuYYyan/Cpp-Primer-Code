#include <iostream>
#include <vector>

using namespace std;

template <typename T>
typename T::value_type top(const T &c) {
    if (!c.empty())
        return c.back(); // ���������������͵Ķ��󲻿գ��������������һ��Ԫ��
    else
        return typename T::value_type();
        // ���������������͵Ķ���Ϊ�գ�����һ��������Ԫ�����͵�Ĭ��ֵ
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << top(v) << endl; // 5
    // cout << int() << endl;
}