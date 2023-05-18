// 本程序编译没通过，但不知道啥原因草了
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

class StrBlobPtr; //前向声明

class StrBlob
{
    friend class StrBlobPtr; //声明为友元类
    private:
        shared_ptr<vector<string>> data;
        void check(vector<string>::size_type i, const string &msg) const;
    public:
        StrBlob();
        StrBlob(initializer_list<string> il); //可变参数形参
        vector<string>::size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();
        string &front();
        string &back();
        const string &front() const;
        const string &back() const;
        StrBlobPtr begin() { return StrBlobPtr(*this); } //调用构造函数，第二个形参使用默认参数0
        StrBlobPtr end();
};

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

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret; //ret是StrBlobPtr对象，调用拷贝构造函数
}

class StrBlobPtr
{
    private:
        weak_ptr<vector<string>> wptr;
        vector<string>::size_type curr;
        shared_ptr<vector<string>> check(vector<string>::size_type i, const string &msg) const;
    public:
        StrBlobPtr() : curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        string &deref() const; //解引用
        StrBlobPtr &incr(); //前缀递增
        bool operator!=(const StrBlobPtr &p) { return p.curr != this->curr; }
};

shared_ptr<vector<string>> StrBlobPtr::check(vector<string>::size_type i, const string &msg) const
{
    auto ret = wptr.lock(); //检查vector是否还存在
    if (!ret)
        throw runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end"); //检查vector是否还存在
    return (*p)[curr]; //(*p)是对象所指向的vector
    //智能指针p的类型是shared_ptr<vector<string>>
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr"); //检查vector是否还存在
    ++curr;
    return *this; //返回指针所指向的对象，即StrBlobPtr对象
}

int main()
{
    StrBlob b;
    string str;

    while(getline(cin, str))
        b.push_back(str);

    for(StrBlobPtr sbp = b.begin(); sbp != b.end(); sbp.incr())
        cout << sbp.deref() << endl; //解引用
    
    return 0;
}