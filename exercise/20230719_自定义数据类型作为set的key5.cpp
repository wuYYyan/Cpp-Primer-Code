#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v){}
    int val;
};

// �����˺�����������ָ������
bool compare2(const Foo& f1, const Foo& f2)
{
    return f1.val < f2.val;
}

int main(int argc, char const *argv[])
{
    // �����壺ʹ�������Զ���ĺ���ָ�����ͣ�ʵ�ִ�С��������
    // ��������������͵Ķ���ʱ����Ҫ�ṩһ����Ҫʹ�õĲ�����ָ��
    // ��compare2����ʼ��s5�����ʾ����s5�����Ԫ��ʱ��ͨ������compare2���Ƚ�Ԫ�صĴ�С
    std::set<Foo, bool(*)(const Foo&, const Foo&)> s5(compare2);
    // std::set<Foo, decltype(compare2)*> s5(compare2);
    s5.insert(Foo(1024));
    s5.insert(Foo(42));
    s5.insert(Foo(102));
    for(auto it = s5.begin(); it != s5.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    return 0;
}