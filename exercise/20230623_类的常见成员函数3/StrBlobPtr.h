#ifndef __STRBLOBPTR_H__
#define __STRBLOBPTR_H__

#include <vector>
#include <memory>
#include <string>
#include "StrBlob.h"

using namespace std;

// 对于访问一个不存在元素的尝试，StrBlobPtr抛出一个异常
class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
    friend bool nqr(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

    public:
        StrBlobPtr() : curr(0) { }
        StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

        string &deref() const;
        StrBlobPtr &incr(); //前缀递增
        StrBlobPtr &decr(); //前缀递减

        // 对于下标运算符，一般定义两个重载版本
        // 一个返回普通引用，一个是const成员函数且返回常量引用
        string &operator[](size_t n) { return (*wptr.lock())[n]; }
        const string &operator[](size_t n) const { return (*wptr.lock())[n]; }

        // 前置运算符返回递增或递减后对象的引用
        StrBlobPtr &operator++();
        StrBlobPtr &operator--();

        // 后置递增递减运算符返回对象的原值(递增或递减之前的值)
        StrBlobPtr operator++(int);
        StrBlobPtr operator++(int);

        // 重载加法和减法运算符
        StrBlobPtr &operator+=(size_t n);
        StrBlobPtr &operator-=(size_t n);
        StrBlobPtr operator+(size_t n);
        StrBlobPtr operator-(size_t n);

        // 重载成员访问运算符
        string &operator*() const {
            auto p = check(curr, "dereference past end");
            return (*p)[curr];
        }
        string *operator->() const {
            // 将实际工作委托给解引用运算符
            return &this->operator*();
        }

    private:
        // 若检查成功，函数check()函数返回一个指向vector的shared_ptr
        shared_ptr<vector<string>> check(size_t, const string &) const;
        
        // 保存一个weak_ptr，意味着底层的vector可能会被销毁
        weak_ptr<vector<string>> wptr;
        size_t curr; //当前在数组中的位置
};

#endif