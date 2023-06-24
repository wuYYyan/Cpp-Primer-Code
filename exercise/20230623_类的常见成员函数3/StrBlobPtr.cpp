#include "StrBlobPtr.h"

bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
        // 当两个指针都为空，或指向相同元素时，两者相等
    else 
        return false; //指向不同的vector时，不等
}

bool nqr(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
        return (!r || lhs.curr == rhs.curr);
        // 当两个指针都为空，或指向相同元素时，两者相等
    else 
        return false; //指向不同的vector时，不等
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        if (!l)
            return false; //两个指针都为空，认为是相等
        return (lhs.curr < rhs.curr); //当指向相同的vector时，比较指向的位置
    }
    else
        return false; //指向不同的vector时，不能比较
        
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        if (!l)
            return false; //两个指针都为空，认为是相等
        return (lhs.curr <= rhs.curr); //当指向相同的vector时，比较指向的位置
    }
    else
        return false;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        if (!l)
            return false; //两个指针都为空，认为是相等
        return (lhs.curr > rhs.curr); //当指向相同的vector时，比较指向的位置
    }
    else
        return false;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        if (!l)
            return false; //两个指针都为空，认为是相等
        return (lhs.curr >= rhs.curr); //当指向相同的vector时，比较指向的位置
    }
    else
        return false;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); //所指向的vector还存在吗？
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; //(*p)是StrBlobPtr类的对象所指向的vector
}

// 前缀递增，返回递增后对象的引用
StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++ curr;
    return *this;
}

// 前缀递减，返回递减后对象的引用
StrBlobPtr &StrBlobPtr::decr()
{
    -- curr;
    check(-1, "decrement past begin of StrBlob Ptr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator++()
{
    // 如果已经指向了容器的尾后位置，则无法继续递增
    check(curr, "increment past end of StrBlobPtr");
    ++ curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    // 如果curr是0，则继续递减会产生无效下标
    -- curr;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this; //记录原值并返回
    ++*this; //调用前置递增运算符
    return ret;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this; //记录原值并返回
    --*this; //调用前置递减运算符
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "decrement past end of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n)
{
    auto ret = *this;
    ret += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n)
{
    auto ret = *this;
    ret -= n;
    return ret;
}