#include <stdio.h>

int main()
{
    // ѡ����1
    unsigned int a = 0XFFFF;
    printf("%u\n", a); // 65535

    // ѡ����2
    char *ps = "wuyan";
    printf("%c\n", ps[0]); // w
    printf("%c\n", ps[3]); // a
    printf("%s\n", ps); // wuyan
    ps[3] = 'y'; // error����������ж��޷�ִ�У�
    // ��Ϊpsָ����ǳ��������������������ǲ����޸ĵ�
    printf("%c\n", ps[3]); // a;
    printf("%s\n", ps); // wuyan

    // ѡ����3
    char s[] = "wuyan";
    printf("%d\n", sizeof(s)); // 6�����������������ָ��
    // s += 2; // error���������ǳ����������޸�
    
    // ѡ����4
    int a = 1; int b = 2; // ����һ���ж������
    int c 
     = a + b; // ����һ�����ָ����
    // C++�ǰ��շֺ����������ָ�ģ���Python��ͬ

    // ѡ����5
    // int 123a = 1; // error�����������������ֿ�ͷ
    int _1 = 2; // �����п��԰�����ĸ�����֡��»��ߣ���ֻ������ĸ���»��߿�ͷ

    // ѡ����6
    
}