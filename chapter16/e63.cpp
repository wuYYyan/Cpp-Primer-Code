#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
int occur(vector<T> &vec, const T &value) {
    int count = 0;
    for (auto &v : vec) {
        if (v == value) {
            ++count;
        }
    }
    return count;
}

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 1, 6, 1, 8};
    cout << occur(vec1, 1) << endl;

    vector<string> vec2 = {"hello", "world", "hello", "cpp", "hello"};
    cout << occur(vec2, string("hello")) << endl;

    return 0;
}