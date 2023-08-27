#include <iostream>
#include <unordered_set>
// #include <unordered_multiset> //��������ͷ�ļ�unordered_set��

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
    // ^�������������������Ķ�����λ��ͬΪ0����ͬΪ1
    // ʹ�ñ�׼��hash���Ͷ���������ÿһ����Ա�����Ĺ�ϣֵ
    // ����ж����Ա��������ο�cppreference�е�д��
}

int main(int argc, char const *argv[])
{
    std::unordered_set<Foo, decltype(hash)*> s;
    // std::unordered_multiset<Foo, Hash> ms;
    s.insert({"42",42});
    s.insert({"1024",1024});

    for (auto it = s.begin(); it != s.end(); it ++)
        std::cout << (*it).str << ": " << (*it).str << std::endl;

    // std::unordered_set<Foo> s2; //ʹ���Զ�����������ʱ�������ع�ϣ�����������﷨�ǷǷ���

    return 0;
}