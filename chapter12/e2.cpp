#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

class StrBlob
{
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

int main()
{
    StrBlob b1;

    {
        StrBlob b2 = {"a", "an", "the"}; //发生了隐式类型转换
        b1 = b2;
        b2.push_back("Hello");
        cout << b2.size() << endl;
    }
    
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    return 0;
}