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
    // ʹ��using��������һ��������
    using BookSet = unordered_multiset<Book, decltype(hasher) *, decltype(eqOp) *>;
    // ʹ�ø����Ͷ���һ������������ͬʱҪ����������Ҫ��Ĳ���
    BookSet bs(42, hasher, eqOp);

    return 0;
}