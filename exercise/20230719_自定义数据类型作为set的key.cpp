#include <iostream>
#include <set>
#include <map>

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
    // bool operator==(const Foo& o) const
    // {
    //     return val == o.val;
    // }
};

struct Comp
{
    // ����ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    bool operator()(const Foo& f1, const Foo& f2) const
    {
        return f1.val < f2.val;
    }
};

// �����˺�����������ָ������
bool compare2(const Foo& f1, const Foo& f2)
{
    return f1.val < f2.val;
}

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

    std::cout << "----------------" << std::endl;

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

    std::cout  << "----------------" << std::endl;

    // ���������ڶ���ģ�����ʹ��[��׼�ⶨ��Ŀɵ��ö���ģ����greater]����Ĭ������ʽ��ʵ�ִӴ�С����
    // ���ַ���Ҫ�����ڱ�������>�������������뱨�����������ص�<���������
    std::set<Foo, std::greater<Foo>> s3;
    s3.insert(Foo(1024));
    s3.insert(Foo(42));
    s3.insert(Foo(102));
    for(auto it = s3.begin(); it != s3.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    std::cout << "----------------" << std::endl;

    // lambda���ʽ����
    auto compare1 = [](const Foo& f1, const Foo& f2) 
    {
        return f1.val < f2.val;
    };

    // �����ģ�ʹ��lambda���ʽ��Ϊset�ĵڶ���ģ�������ʵ�ִ�С���������벻����Ϊɶ����
    // std::set<Foo, decltype(compare1)}> s4(compare1);
    // s4.insert(Foo(1024));
    // s4.insert(Foo(42));
    // s4.insert(Foo(102));
    // for(auto it = s4.begin(); it != s4.end(); ++it)
    // {
    //     std::cout << it->val << std::endl;
    // }

    std::cout << "----------------" << std::endl;

    // �����壺ʹ�������Զ���ĺ���ָ�����ͣ�ʵ�ִ�С��������
    // ��������������͵Ķ���ʱ����Ҫ�ṩһ����Ҫʹ�õĲ�����ָ��
    // ��compare2����ʼ��s5�����ʾ����s5�����Ԫ��ʱ��ͨ������compare2���Ƚ�Ԫ�صĴ�С
    std::set<Foo, bool(*)(const Foo&, const Foo&)> s5(compare2);
    // std::set<Foo, decltype(compare)*> s5(compare);
    s5.insert(Foo(1024));
    s5.insert(Foo(42));
    s5.insert(Foo(102));
    for(auto it = s5.begin(); it != s5.end(); ++it)
    {
        std::cout << it->val << std::endl;
    }

    std::cout << "----------------" << std::endl;

    return 0;
}