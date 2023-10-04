#include <string>
#include "c5.h"

using namespace std;

pair<string *, string *> StrVec::alloc_n_copy(const string *beg, const string *ed)
{
    string *data = alloc.allocate(ed - beg); //�����ڴ�ռ䱣�������Χ�ڵ�Ԫ��
    return {data, uninitialized_copy(beg, ed, data)};
    // ���ؿ������֮���Ԫ����������
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
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
        // alloc.construct(dest ++, *elem ++); //���õ�string�Ŀ������캯��
    
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

StrVec::StrVec(StrVec &&rhs) noexcept
    : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //�ͷ�ԭ����ɵ��ڴ�ռ�
    elements = new_data.first;
    cap = first_free = new_data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
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

int main()
{
    return 0;
}