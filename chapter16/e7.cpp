#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T, size_t N>
constexpr int my_size(const T (&a)[N])
{
    return N;
}

template <typename T, size_t N>
void print(const T (&a)[N])
{
    // 所传入的容器不一定重载了下标运算符
    // for (size_t i = 0; i < N; ++i)
    //     cout << a[i] << " ";

    for (int i = 0; i < my_size(a); ++i)
        cout << a[i] << " ";

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