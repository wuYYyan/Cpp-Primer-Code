#include <iostream>
#include <vector>
#include <string>
#include <cstring>

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

template <>
int occur(vector<const char *> &vec, const char * const &value) {
    int count = 0;
    for (auto &v : vec) {
        if (!strcmp(v, value)) {
            ++count;
        }
    }
    cout << "specialized version" << endl; // for testing
    return count;
}

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 1, 6, 1, 8};
    cout << occur(vec1, 1) << endl;

    vector<string> vec2 = {"hello", "world", "hello", "cpp", "hello"};
    cout << occur(vec2, string("hello")) << endl;

    vector<const char *> vec3 = {"hello", "world", "hello", "cpp", "hello"};
    const char *p = "hello";
    cout << occur(vec3, p) << endl;
    // cout << occur(vec3, "hello") << endl;

    return 0;
}