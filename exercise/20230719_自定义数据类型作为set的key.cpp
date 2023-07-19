#include <iostream>
#include <set>
#include <map>

using namespace std;

struct Foo
{
    Foo(int v):val(v){}
    int val;

    // ����ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    bool operator<(const Foo& o) const
    {
        return val < o.val;
    }

    // ����ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    bool operator>(const Foo& o) const
    {
        return val > o.val;
    }

    // ����ͬʱ���� < �� == ������������ܲ������������벻һ������
    bool operator==(const Foo& o) const
    {
        return val == o.val;
    }
};

struct Comp
{
    // ����ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    bool operator()(const Foo& f1, const Foo& f2) const
    {
        return f1.val < f2.val;
    }
};

bool compare1(const Foo& f1, const Foo& f2);

int main(int argc, char const *argv[])
{
    // ����һ��������������������<�������Ĭ��ʵ�ִ�С��������
    // ��Ȼ������key�ظ�����������value�ظ�������Ҳ����Ҫ����==�����
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

    cout << "----------------" << endl;

    // �������������Զ����࣬����������operator()�������ʹ�����Ϊ�ɵ��ö���
    // ��Ϊset�ĵڶ���ģ�������ʵ�ִ�С�������������Զ���ıȽ����������������ص������
    std::set<Foo, Comp> s2;
    s2.insert(Foo(1024));
    s2.insert(Foo(42));
    s2.insert(Foo(102));
    for(auto it = s2.begin(); it != s2.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    cout  << "----------------" << endl;

    // ���������ڶ���ģ�����ʹ�ñ�׼�ⶨ��Ŀɵ��ö���ģ����greater����Ĭ������ʽ��ʵ�ִӴ�С����
    // ���ַ���Ҫ�����ڱ�������>�������������뱨�����������ص�<���������
    std::set<Foo, greater<Foo>> s3;
    s3.insert(Foo(1024));
    s3.insert(Foo(42));
    s3.insert(Foo(102));
    for(auto it = s3.begin(); it != s3.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    cout << "----------------" << endl;

    // ʹ��lambda���ʽ��Ϊset�ĵڶ���ģ�������ʵ�ִӴ�С������ʱδ���
    // std::set<Foo, [val](const Foo& f) {return val > f.val;}> s4;
    // s4.insert(Foo(1024));
    // s4.insert(Foo(42));
    // s4.insert(Foo(102));
    // for(auto it = s4.begin(); it != s4.end(); ++it)
    // {
    //     std::cout << it->val << std::endl;
    // }

    return 0;
}

bool compare1(const Foo& f1, const Foo& f2)
{
    return f1.val < f2.val;
}