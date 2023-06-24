#include "StrBlob.h"
#include "StrBlobPtr.h"

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs.data == rhs.data; //所指向的vector相等
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data; //利用容器vector重载的关系运算符
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data <= *rhs.data; //利用容器vector重载的关系运算符
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data > *rhs.data; //利用容器vector重载的关系运算符
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data >= *rhs.data; //利用容器vector重载的关系运算符
}

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(vector<string>::size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob"); //检查是否为空
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob"); //检查是否为空
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob"); //检查是否为空
    return data->back();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob"); //检查是否为空
    return data->front();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob"); //检查是否为空
    return data->back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}