#ifndef __E49_H__
#define __E49_H__

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class StrVec
{
    private:
        string *elements;
        string *first_free;
        string *cap;
        allocator<string> alloc;

        pair<string *, string *> alloc_n_copy(const string *, const string *); //分配内存空间并拷贝给定范围内的元素
        void free(); //销毁构造的元素并释放内存
        void reallocate(); //在内存用完时重新分配内存
        void chk_n_alloc() //检查是否至少有一个容纳新元素的空间
        {
            if (size() == capacity())
                reallocate();
        }
    public:
        StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
        StrVec(const StrVec &); //拷贝构造函数 
        StrVec(StrVec &&) noexcept; //移动构造函数
        StrVec &operator=(const StrVec &); //拷贝赋值运算符
        StrVec &operator=(StrVec &&rhs) noexcept; //移动赋值运算符
        ~StrVec();
        void push_back(const string &);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements;}
        string *begin() const { return elements; }
        string *end() const { return first_free; }
};

#endif