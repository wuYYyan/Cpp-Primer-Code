#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

class StrBlobPtr; //前向声明

class StrBlob
{
    friend class StrBlobPtr; //声明为友元类，方便StrBlobPtr类访问StrBlob类的私有成员
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
        StrBlobPtr begin() { return StrBlobPtr(*this); }
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
    return ret;
}

//伴随指针类具体指向底层容器中的某个元素，而不是指向容器本身
class StrBlobPtr
{
    private:
        weak_ptr<vector<string>> wptr;
        vector<string>::size_type curr;
        shared_ptr<vector<string>> check(vector<string>::size_type, const string &msg) const; //注意返回类型
    public:
        StrBlobPtr() : curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
        //这个构造函数的写法不允许将一个StrBlob对象的引用赋值给StrBlobPtr对象，因此形参是非 const 类型的
        string &deref() const; //解引用
        StrBlobPtr &incr(); //前缀递增
};

shared_ptr<vector<string>> StrBlobPtr::check(vector<string>::size_type i, const string &msg) const
{
    auto ret = wptr.lock(); //检查vector是否还存在
    if (!ret)
        throw runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
    //lock()函数的返回类型是shared_ptr<vector<string>>
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
    return *this; //返回指针所指向的对象，即StrBlobPtr对象本身
}

int main()
{
    StrBlob b1;

    { //新作用域
        StrBlob b2 = {"a", "an", "the"}; //发生了隐式类型转换
        b1 = b2; //类对象的赋值，即类的私有数据成员赋值，私有数据成员是智能指针，也就是智能指针的赋值
        //因此b1和b2共享同一个vector<string>对象
        b2.push_back("Hello");
        cout << b2.size() << endl;
    } //程序运行离开b2的作用域时，b2被销毁，但是b1仍然可以访问b2中的元素
    
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    return 0;
}