#include <iostream>
#include <set>

using namespace std;

struct Foo
{
    Foo(int v):val(v){}
    int val;

    bool operator<(const Foo& o) const
    {
        return val < o.val;
    }

    bool operator>(const Foo& o) const
    {
        return val > o.val;
    }
};

struct Comp
{
    bool operator()(const Foo& f1, const Foo& f2) const
    {
        return f1.val < f2.val;
    }
};

int main(int argc, char const *argv[])
{
    // ����һ����������������<�������Ĭ��ʵ�ִ�С��������
    std::set<Foo> s1;
    s1.insert(Foo(1024));
    s1.insert(Foo(42));
    for(auto it = s1.begin(); it != s1.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    cout << "----------------" << endl;

    // �������������Զ���Ƚ�������������()�����
    // ��Ϊset�ĵڶ���ģ�������ʵ�ִ�С��������
    std::set<Foo, Comp> s2;
    s2.insert(Foo(1024));
    s2.insert(Foo(42));
    for(auto it = s2.begin(); it != s2.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    cout  << "----------------" << endl;

    // �ڶ���ģ���������Ƚ����ͣ�ʵ�ִӴ�С����
    std::set<Foo, greater<Foo>> s3;
    s3.insert(Foo(1024));
    s3.insert(Foo(42));
    for(auto it = s3.begin(); it != s3.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    return 0;
}