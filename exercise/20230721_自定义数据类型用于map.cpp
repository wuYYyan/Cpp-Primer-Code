#include <iostream>
#include <map>

using namespace std;

struct Foo
{
    Foo(int v):val(v){}
    int val;

    // 返回值为true表示第一个参数的优先级高于第二个参数
    // bool operator<(const Foo& o) const
    // {
    //     return val < o.val;
    // }

    // 返回值为true表示第一个参数的优先级高于第二个参数
    // bool operator>(const Foo& o) const
    // {
    //     return val > o.val;
    // }

    // bool operator==(const Foo& o) const
    // {
    //     return val == o.val;
    // }
};

int main()
{
    // 自定义数据类型作为key类型时，必须在类内重载<运算符和==运算符，否则编译报错
    // 不能用重载的>运算符代替
    // map<Foo, int> m1;
    // m1.insert(std::make_pair(Foo(1024), 1));
    // m1.insert(std::make_pair(Foo(42), 2));
    // m1.insert(std::make_pair(Foo(102), 3));
    // m1.insert(std::make_pair(Foo(102), 3));
    // m1.insert(std::make_pair(Foo(102), 3));
    // m1.insert(std::make_pair(Foo(102), 3));
    // m1.insert(std::make_pair(Foo(102), 3));
    // for (auto it = m1.begin(); it != m1.end(); ++it)
    // {
    //     std::cout << it->first.val << " " << it->second << std::endl;
    // }

    cout << "----------------" << endl;

    // map默认以第一关键字排序【从小到大排序】
    // 当自定义数据类型作为value类型时，不需要重载任何运算符
    map<int, Foo> m2;
    m2.insert(std::make_pair(1, Foo(1024)));
    m2.insert(std::make_pair(2, Foo(42)));
    m2.insert(std::make_pair(3, Foo(102)));
    for (auto it = m2.begin(); it != m2.end(); ++it)
    {
        std::cout << it->first << " " << it->second.val << std::endl;
    }


    return 0;
}
    

