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

// �Զ����ϣ������==��������Ǽȿ��Է����Զ������У��ֿ��Ե�����Ϊһ���ṹ��
// ��������Ϊһ����������˹��о��ַ�ʽ
struct Hash
{
    size_t operator()(const Foo& f) const
    {
        return std::hash<std::string>()(f.str) ^ std::hash<int>()(f.val);
        // ^�������������������Ķ�����λ��ͬΪ0����ͬΪ1
        // ʹ�ñ�׼��hash���Ͷ���������ÿһ����Ա�����Ĺ�ϣֵ������ж����Ա��������Զ����ϣֵʹ��������
    }
};

int main(int argc, char const *argv[])
{
    std::unordered_set<Foo, Hash> s;
    // std::unordered_multiset<Foo, Hash> ms;
    s.insert({"42",42});
    s.insert({"1024",1024});

    // std::unordered_set<Foo> s2; //ʹ���Զ�����������ʱ�������ع�ϣ�����������﷨�ǷǷ���

    return 0;
}