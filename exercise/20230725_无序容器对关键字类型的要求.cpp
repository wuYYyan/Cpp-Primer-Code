// C++ Primer P396
#include <iostream>
#include <unordered_set>

using namespace std;

struct Book {
    string bookNo;
};

size_t hasher(const Book &sd)
{
    return hash<string>()(sd.bookNo);
}

bool eqOp(const Book &lhs, const Book &rhs)
{
    return lhs.bookNo == rhs.bookNo;
}

int main()
{
    // 使用using声明定义一种新类型
    using BookSet = unordered_multiset<Book, decltype(hasher) *, decltype(eqOp) *>;
    // 使用该类型定义一个无序容器，同时要传入类型所要求的参数
    BookSet bs(42, hasher, eqOp);

    return 0;
}