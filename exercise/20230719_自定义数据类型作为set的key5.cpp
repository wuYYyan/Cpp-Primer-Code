#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v){}
    int val;
};

// 借助此函数声明函数指针类型
bool compare2(const Foo& f1, const Foo& f2)
{
    return f1.val < f2.val;
}

int main(int argc, char const *argv[])
{
    // 方法五：使用类外自定义的函数指针类型，实现从小到大排序
    // 当定义此容器类型的对象时，需要提供一个想要使用的操作的指针
    // 用compare2来初始化s5，这表示当向s5中添加元素时，通过调用compare2来比较元素的大小
    std::set<Foo, bool(*)(const Foo&, const Foo&)> s5(compare2);
    // std::set<Foo, decltype(compare2)*> s5(compare2);
    s5.insert(Foo(1024));
    s5.insert(Foo(42));
    s5.insert(Foo(102));
    for(auto it = s5.begin(); it != s5.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    return 0;
}