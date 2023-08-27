#include <iostream>
#include <unordered_set>
// #include <unordered_multiset> //都包含在头文件unordered_set中

struct Foo
{
    std::string str;
    int val;
    bool operator==(const Foo& o) const
    {
        return (str == o.str) && (val == o.val);
    }
};

// 自定义哈希函数与==运算符都是既可以放在自定义类中，又可以单独成为一个结构体
// 还可以作为一个函数，因此共有九种方式
struct Hash
{
    size_t operator()(const Foo& f) const
    {
        return std::hash<std::string>()(f.str) ^ std::hash<int>()(f.val);
        // ^是异或运算符，两个数的二进制位相同为0，不同为1
        // 使用标准库hash类型对象来计算每一个成员变量的哈希值，如果有多个成员变量，则对多个哈希值使用异或操作
    }
};

int main(int argc, char const *argv[])
{
    std::unordered_set<Foo, Hash> s;
    // std::unordered_multiset<Foo, Hash> ms;
    s.insert({"42",42});
    s.insert({"1024",1024});

    // std::unordered_set<Foo> s2; //使用自定义数据类型时必须重载哈希函数，否则语法是非法的

    return 0;
}