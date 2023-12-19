#include <iostream>
#include <string>

using namespace std;

template <typename T, size_t N> // ���Ͳ���������Ͳ���
void print(const T (&a)[N])
{
    // �������������һ���������±������
    // for (size_t i = 0; i < N; ++i)
    //     cout << a[i] << " ";

    for (auto p = begin(a); p != end(a); ++p)
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