#include <iostream>
#include <string>

using namespace std;

template <typename T, size_t N>
const T* my_begin(const T (&a)[N])
{
    return &a[0];
}

template <typename T, size_t N>
const T* my_end(const T (&a)[N])
{
    return &a[0] + N;
}

template <typename T, size_t N>
void print(const T (&a)[N])
{
    // 所传入的容器不一定重载了下标运算符
    // for (size_t i = 0; i < N; ++i)
    //     cout << a[i] << " ";

    for (auto p = my_begin(a); p != my_end(a); ++p)
        cout << *p << " ";

    cout << endl;
}

int main()
{
    int v[] = {0, 2, 4, 6, 8, 10};
    string l[] = {"hello", "world", "!"};

    print(v);
    print(l);

    return 0;
}