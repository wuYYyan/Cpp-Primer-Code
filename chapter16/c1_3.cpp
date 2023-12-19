#include <iostream>
#include <vector>

using namespace std;

template <typename T>
typename T::value_type top(const T &c) {
    if (!c.empty())
        return c.back(); // 如果传入的容器类型的对象不空，返回容器的最后一个元素
    else
        return typename T::value_type();
        // 如果传入的容器类型的对象为空，返回一个容器中元素类型的默认值
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << top(v) << endl; // 5
    // cout << int() << endl;
}