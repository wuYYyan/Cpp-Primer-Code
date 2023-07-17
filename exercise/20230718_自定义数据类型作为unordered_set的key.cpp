#include <iostream>
#include <unordered_set>

struct Foo
{
    std::string str;
    int val;
    bool operator==(const Foo& o) const
    {
        return str == o.str && val == o.val;
    }
};

struct Hash
{
    size_t operator()(const Foo& f) const
    {
        return std::hash<std::string>()(f.str) ^ std::hash<int>()(f.val);
    }
};

int main(int argc, char const *argv[])
{
    std::unordered_set<Foo,Hash> s;
    s.insert({"42",42});
    s.insert({"1024",1024});
    return 0;
}