#include <string>
#include "e43.h"

using namespace std;

pair<string *, string *> StrVec::alloc_n_copy(const string *beg, const string *ed)
{
    string *data = alloc.allocate(ed - beg); //分配内存空间保存给定范围内的元素
    return {data, uninitialized_copy(beg, ed, data)};
    // 返回拷贝完成之后的元素所在区间
}

void StrVec::free()
{
    if (elements)
    {
        /*for (auto p = first_free; p != elements;)
            alloc.destroy(--p);*/
        for_each(elements, first_free, [&](string &s) {alloc.destroy(&s);});
        // 对范围中的每一个元素应用lambda表达式
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_data = alloc.allocate(new_capacity);
    
    auto dest = new_data;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest ++, std::move(*elem ++));
        // alloc.construct(dest ++, *elem ++); //会用到string的拷贝构造函数
    
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

StrVec::StrVec(const StrVec &rhs)
{
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(initializer_list<string> il)
{
    auto new_data = alloc_n_copy(il.begin(), il.end());
    elements = new_data.first;
    cap = first_free = new_data.second;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //释放原对象旧的内存空间
    elements = new_data.first;
    cap = first_free = new_data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free ++, s);
}

void StrVec::reserve(size_t n)
{
    if (n <= capacity())
        return;

    auto new_data = alloc.allocate(n);
    
    auto dest = new_data;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest ++, std::move(*elem ++));
        // alloc.construct(dest ++, *elem ++); //会用到string的拷贝构造函数
    
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + n;
}

void StrVec::resize(size_t n)
{
    if (n > size())
        while (size() < n)
            push_back(" ");
    else if (n < size())
        while (size() > n)
            alloc.destroy(--first_free);
}

int main()
{
    return 0;
}