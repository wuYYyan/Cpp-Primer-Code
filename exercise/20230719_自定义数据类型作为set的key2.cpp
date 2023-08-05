#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v){}
    int val;
};

struct Comp
{
    // ����ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    bool operator()(const Foo& f1, const Foo& f2) const
    {
        return f1.val < f2.val;
    }
};

int main(int argc, char const *argv[])
{
    // �������������Զ���Ƚ����࣬����������operator()�������ʹ�����Ϊ�ɵ��ö���
    // ��Ϊset�ĵڶ���ģ�������ʵ�ִ�С�������������Զ���ıȽ����������������ص������
    std::set<Foo, Comp> s2;
    s2.insert(Foo(1024));
    s2.insert(Foo(42));
    s2.insert(Foo(102));
    for(auto it = s2.begin(); it != s2.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    return 0;
}