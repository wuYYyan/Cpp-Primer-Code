#include <iostream>
#include <map>

using namespace std;

struct Foo
{
    Foo(int v):val(v){}
    int val;

    // ����ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    // bool operator<(const Foo& o) const
    // {
    //     return val < o.val;
    // }

    // ����ֵΪtrue��ʾ��һ�����������ȼ����ڵڶ�������
    // bool operator>(const Foo& o) const
    // {
    //     return val > o.val;
    // }

    // bool operator==(const Foo& o) const
    // {
    //     return val == o.val;
    // }
};

int main()
{
    // �Զ�������������Ϊkey����ʱ����������������<�������==�������������뱨��
    // ���������ص�>���������
    // map<Foo, int> m1;
    // m1.insert(std::make_pair(Foo(1024), 1));
    // m1.insert(std::make_pair(Foo(42), 2));
    // m1.insert(std::make_pair(Foo(102), 3));
    // m1.insert(std::make_pair(Foo(102), 3));
    // m1.insert(std::make_pair(Foo(102), 3));
    // m1.insert(std::make_pair(Foo(102), 3));
    // m1.insert(std::make_pair(Foo(102), 3));
    // for (auto it = m1.begin(); it != m1.end(); ++it)
    // {
    //     std::cout << it->first.val << " " << it->second << std::endl;
    // }

    cout << "----------------" << endl;

    // mapĬ���Ե�һ�ؼ������򡾴�С��������
    // ���Զ�������������Ϊvalue����ʱ������Ҫ�����κ������
    map<int, Foo> m2;
    m2.insert(std::make_pair(1, Foo(1024)));
    m2.insert(std::make_pair(2, Foo(42)));
    m2.insert(std::make_pair(3, Foo(102)));
    for (auto it = m2.begin(); it != m2.end(); ++it)
    {
        std::cout << it->first << " " << it->second.val << std::endl;
    }


    return 0;
}
    

