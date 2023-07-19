#include <iostream>
#include <unordered_set>
// #include <unordered_multiset>

struct Foo
{
    std::string str;
    int val;
    bool operator==(const Foo& o) const
    {
        return (str == o.str) && (val == o.val);
    }
};

struct Hash
{
    size_t operator()(const Foo& f) const
    {
        return std::hash<std::string>()(f.str) ^ std::hash<int>()(f.val);
        // ^是异或运算符，两个数的二进制位相同为0，不同为1
        // 上面的语句暂时不理解
    }
};

int main(int argc, char const *argv[])
{
    std::unordered_set<Foo, Hash> s;
    std::unordered_multiset<Foo, Hash> ms;
    s.insert({"42",42});
    s.insert({"1024",1024});

    // std::unordered_set<Foo> s2; //使用自定义数据类型时必须重载哈希函数

    return 0;
}