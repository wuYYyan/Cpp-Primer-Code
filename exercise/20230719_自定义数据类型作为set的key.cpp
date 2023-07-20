#include <iostream>
#include <set>
#include <map>

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
    // bool operator==(const Foo& o) const
    // {
    //     return val == o.val;
    // }
};

struct Comp
{
    // 返回值为true表示第一个参数的优先级高于第二个参数
    bool operator()(const Foo& f1, const Foo& f2) const
    {
        return f1.val < f2.val;
    }
};

// 借助此函数声明函数指针类型
bool compare2(const Foo& f1, const Foo& f2)
{
    return f1.val < f2.val;
}

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

    std::cout << "----------------" << std::endl;

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

    std::cout  << "----------------" << std::endl;

    // 方法三：第二个模板参数使用[标准库定义的可调用对象模板类greater]重载默认排序方式，实现从大到小排序
    // 这种方法要求类内必须重载>运算符，否则编译报错，不能用重载的<运算符代替
    std::set<Foo, std::greater<Foo>> s3;
    s3.insert(Foo(1024));
    s3.insert(Foo(42));
    s3.insert(Foo(102));
    for(auto it = s3.begin(); it != s3.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    std::cout << "----------------" << std::endl;

    // lambda表达式类型
    auto compare1 = [](const Foo& f1, const Foo& f2) 
    {
        return f1.val < f2.val;
    };

    // 方法四：使用lambda表达式作为set的第二个模板参数，实现从小到大排序，想不明白为啥报错
    // std::set<Foo, decltype(compare1)}> s4(compare1);
    // s4.insert(Foo(1024));
    // s4.insert(Foo(42));
    // s4.insert(Foo(102));
    // for(auto it = s4.begin(); it != s4.end(); ++it)
    // {
    //     std::cout << it->val << std::endl;
    // }

    std::cout << "----------------" << std::endl;

    // 方法五：使用类外自定义的函数指针类型，实现从小到大排序
    // 当定义此容器类型的对象时，需要提供一个想要使用的操作的指针
    // 用compare2来初始化s5，这表示当向s5中添加元素时，通过调用compare2来比较元素的大小
    std::set<Foo, bool(*)(const Foo&, const Foo&)> s5(compare2);
    // std::set<Foo, decltype(compare)*> s5(compare);
    s5.insert(Foo(1024));
    s5.insert(Foo(42));
    s5.insert(Foo(102));
    for(auto it = s5.begin(); it != s5.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    std::cout << "----------------" << std::endl;

    return 0;
}