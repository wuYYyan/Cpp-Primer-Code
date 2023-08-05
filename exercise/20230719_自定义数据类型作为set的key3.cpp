#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v){}
    int val;

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

int main(int argc, char const *argv[])
{
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

    return 0;
}