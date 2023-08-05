#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v){}
    int val;
};

int main(int argc, char const *argv[])
{
    // lambda���ʽ��������һ���������������Խ��丳ֵ��һ��������Ҳ����ֱ��ʹ��
    auto compare1 = [](const Foo& f1, const Foo& f2) 
    {
        return f1.val < f2.val;
    };

    // �����ģ�ʹ��lambda���ʽ��Ϊset�ĵڶ���ģ�������ʵ�ִ�С���������벻����Ϊɶ����
    std::set<Foo, decltype(compare1)> s4(compare1);
    s4.insert(Foo(1024));
    s4.insert(Foo(42));
    s4.insert(Foo(102));
    for(auto it = s4.begin(); it != s4.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    return 0;
}