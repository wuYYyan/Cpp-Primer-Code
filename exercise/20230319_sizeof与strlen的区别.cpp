#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a = 4;
    // ������sizeof()�Ĳ��������Ǳ��������ͣ�Ҳ�����Ǳ�����
    cout << sizeof(int) << ' ' << sizeof(a) << endl; //�����Ϊ4

    char p[10] = "wuyan";
    char q[] = "WUYAN";
    cout << sizeof(p) << ' ' << strlen(p) << endl; //ǰ�����10���������5
    cout << sizeof(q) << ' ' << strlen(q) << endl; //ǰ�����6���������5
    // ˵��������sizeof()���ص��Ǳ�����ռ�ڴ�Ĵ�С(�Զ���ӿ��ַ�)��������strlen()���ص����ַ����ĳ��ȣ������������ַ�
    // ��sizeof������У����Ὣ����������Ϊ��һ��Ԫ�صĵ�ַ(C++ Primer P143�����鲻��ת��Ϊָ����������)
    // ��˶����ַ�����q����ռ�ڴ�ռ��С������Ҫ����ĩβ���ַ�'\0'ռ�õ�һ���ֽ�
    // ���䣺strlen()�����ķ���ֵ���ַ����ĳ��ȣ���size()�����Ĺ���һ��

    return 0;
}