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


size_t hash(const Foo& f)
{
    return (std::hash<std::string>()(f.str)) ^ (std::hash<int>()(f.val) << 1);
    // ^是异或运算符，两个数的二进制位相同为0，不同为1
    // 使用标准库hash类型对象来计算每一个成员变量的哈希值
    // 如果有多个成员变量，则参考cppreference中的写法
}

int main(int argc, char const *argv[])
{
    std::unordered_set<Foo, decltype(hash)*> s;
    // std::unordered_multiset<Foo, Hash> ms;
    s.insert({"42",42});
    s.insert({"1024",1024});

    for (auto it = s.begin(); it != s.end(); it ++)
        std::cout << (*it).str << ": " << (*it).str << std::endl;

    // std::unordered_set<Foo> s2; //使用自定义数据类型时必须重载哈希函数，否则语法是非法的

    return 0;
}