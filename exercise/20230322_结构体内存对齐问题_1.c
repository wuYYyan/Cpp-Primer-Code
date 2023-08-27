#include <stdlib.h>
#include <stdio.h>

struct A
{
    char a; //������Ϊ1
    char b; //������Ϊ1
    int c;  //������Ϊ4
};

struct B
{
    char a; //������Ϊ1
    int c;  //������Ϊ4
    char b; //������Ϊ1
};

struct C
{
    char a; //������Ϊ1
    int *p; //������Ϊ8
    int c; //������Ϊ4
};

struct D
{
    char a; //������Ϊ1
    int b; //������Ϊ4
    int *q; //������Ϊ8
};

int main()
{
    printf("size of struct A = %llu\n", sizeof(struct A)); //8
    printf("size of struct B = %llu\n", sizeof(struct B)); //12
    printf("size of struct C = %llu\n", sizeof(struct C)); //24
    printf("size of struct D = %llu\n", sizeof(struct D)); //16

    /*
    �ṹ���С�ļ���Ҫ��ѭ�ṹ���ڴ�������(�ݲ����ǽṹ���Ƕ������)��
    1) ��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ��
    2) ������Ա����ÿ�ζ�Ҫ�ӡ���������������������ĵ�ַ����ʼ���
    3) �ṹ����ܴ�СΪ���и���Ա����������(ÿһ����Ա��������һ��������)��������
    4) ��Ա�����Ķ����� = �ýṹ���Ա��������Ĵ�С�������Ĭ�ϵ�һ���������Ľ�Сֵ
    */

    return 0;
}