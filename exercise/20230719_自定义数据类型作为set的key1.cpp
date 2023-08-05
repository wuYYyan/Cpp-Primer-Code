#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v) { }
    int val;

    // ����ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    bool operator<(const Foo& o) const
    {
        return val < o.val;
    }

    // ����ͬʱ���� < �� == ������������ܲ������������벻һ������
    // bool operator==(const Foo& o) const
    // {
    //     return val == o.val;
    // }
};

int main(int argc, char const *argv[])
{
    // ����һ��������������������<�������Ĭ��ʵ�ִ�С��������
    // ��Ȼ������key�ظ�����������value�ظ�������Ҳ����Ҫ����==�����(C++ Primer P378)
    std::set<Foo> s1;
    s1.insert(Foo(1024));
    s1.insert(Foo(42));
    s1.insert(Foo(102));
    s1.insert(Foo(102));
    s1.insert(Foo(102));
    s1.insert(Foo(102));
    s1.insert(Foo(102));
    for(auto it = s1.begin(); it != s1.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    return 0;
}