#include <iostream>
#include <set>

struct Foo
{
    Foo(int v) : val(v){}
    int val;

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

int main(int argc, char const *argv[])
{
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

    return 0;
}