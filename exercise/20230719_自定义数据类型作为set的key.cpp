#include <iostream>
#include <set>
#include <map>

using namespace std;

struct Foo
{
    Foo(int v):val(v){}
    int val;

    // 返回值为true表示第一个参数的优先级高于第二个参数
    bool operator<(const Foo& o) const
    {
        return val < o.val;
    }

    // 返回值为true表示第一个参数的优先级高于第二个参数
    bool operator>(const Foo& o) const
    {
        return val > o.val;
    }

    // 必须同时重载 < 和 == 运算符，否则功能不完整，但编译不一定报错
    bool operator==(const Foo& o) const
    {
        return val == o.val;
    }
};

struct Comp
{
    // 返回值为true表示第一个参数的优先级高于第二个参数
    bool operator()(const Foo& f1, const Foo& f2) const
    {
        return f1.val < f2.val;
    }
};

bool compare1(const Foo& f1, const Foo& f2);

int main(int argc, char const *argv[])
{
    // 方法一：必须在自身类内重载<运算符，默认实现从小到大排序
    // 虽然不允许key重复，但是允许value重复，而且也不需要重载==运算符
    std::set<Foo> s1;
    s1.insert(Foo(1024));
    s1.insert(Foo(42));
    s1.insert(Foo(102));
    s1.insert(Foo(102));
    s1.insert(Foo(102));
    s1.insert(Foo(102));
    s1.insert(Foo(102));
    for(auto it = s1.begin(); it != s1.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    cout << "----------------" << endl;

    // 方法二：类外自定义类，其中重载了operator()运算符，使该类成为可调用对象
    // 作为set的第二个模板参数，实现从小到大排序，类外自定义的比较器代替了类内重载的运算符
    std::set<Foo, Comp> s2;
    s2.insert(Foo(1024));
    s2.insert(Foo(42));
    s2.insert(Foo(102));
    for(auto it = s2.begin(); it != s2.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    cout  << "----------------" << endl;

    // 方法三：第二个模板参数使用标准库定义的可调用对象模板类greater重载默认排序方式，实现从大到小排序
    // 这种方法要求类内必须重载>运算符，否则编译报错，不能用重载的<运算符代替
    std::set<Foo, greater<Foo>> s3;
    s3.insert(Foo(1024));
    s3.insert(Foo(42));
    s3.insert(Foo(102));
    for(auto it = s3.begin(); it != s3.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    cout << "----------------" << endl;

    // 使用lambda表达式作为set的第二个模板参数，实现从大到小排序，暂时未解决
    // std::set<Foo, [val](const Foo& f) {return val > f.val;}> s4;
    // s4.insert(Foo(1024));
    // s4.insert(Foo(42));
    // s4.insert(Foo(102));
    // for(auto it = s4.begin(); it != s4.end(); ++it)
    // {
    //     std::cout << it->val << std::endl;
    // }

    return 0;
}

bool compare1(const Foo& f1, const Foo& f2)
{
    return f1.val < f2.val;
}