#ifndef __STRBLOB_H__
#define __STRBLOB_H__

#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);

    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);

    public:
        StrBlob();
        StrBlob(initializer_list<string> il); //可变参数形参
        vector<string>::size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        
        // 添加和删除元素
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();

        // 元素访问，成员函数是否为 const 也构成重载
        string &front();
        string &back();
        const string &front() const;
        const string &back() const;

        StrBlobPtr begin();
        StrBlobPtr end();

        // 对于下标运算符，一般定义两个重载版本
        // 一个返回普通引用，一个是const成员函数且返回常量引用
        string &operator[](size_t n) { return (*data)[n]; }
        const string &operator[](size_t n) const { return (*data)[n]; }
    
    private:
        shared_ptr<vector<string>> data; //指向存放字符串的容器的智能指针
        void check(vector<string>::size_type i, const string &msg) const;
};

#endif