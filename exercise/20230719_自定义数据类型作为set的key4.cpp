#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v){}
    int val;
};

int main(int argc, char const *argv[])
{
    // lambda表达式的类型是一个匿名函数，可以将其赋值给一个变量，也可以直接使用
    auto compare1 = [](const Foo& f1, const Foo& f2) 
    {
        return f1.val < f2.val;
    };

    // 方法四：使用lambda表达式作为set的第二个模板参数，实现从小到大排序，想不明白为啥报错
    std::set<Foo, decltype(compare1)> s4(compare1);
    s4.insert(Foo(1024));
    s4.insert(Foo(42));
    s4.insert(Foo(102));
    for(auto it = s4.begin(); it != s4.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    return 0;
}