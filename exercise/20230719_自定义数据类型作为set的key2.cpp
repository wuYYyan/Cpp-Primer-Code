#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v){}
    int val;
};

struct Comp
{
    // 返回值为true表示第一个参数的优先级高于第二个参数
    bool operator()(const Foo& f1, const Foo& f2) const
    {
        return f1.val < f2.val;
    }
};

int main(int argc, char const *argv[])
{
    // 方法二：类外自定义比较器类，其中重载了operator()运算符，使该类成为可调用对象
    // 作为set的第二个模板参数，实现从小到大排序，类外自定义的比较器代替了类内重载的运算符
    std::set<Foo, Comp> s2;
    s2.insert(Foo(1024));
    s2.insert(Foo(42));
    s2.insert(Foo(102));
    for(auto it = s2.begin(); it != s2.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    return 0;
}