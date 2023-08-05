#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v) { }
    int val;

    // 返回值为true表示第一个参数的优先级高于第二个参数
    bool operator<(const Foo& o) const
    {
        return val < o.val;
    }

    // 必须同时重载 < 和 == 运算符，否则功能不完整，但编译不一定报错
    // bool operator==(const Foo& o) const
    // {
    //     return val == o.val;
    // }
};

int main(int argc, char const *argv[])
{
    // 方法一：必须在自身类内重载<运算符，默认实现从小到大排序
    // 虽然不允许key重复，但是允许value重复，而且也不需要重载==运算符(C++ Primer P378)
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

    return 0;
}