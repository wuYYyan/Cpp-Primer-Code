#include <stdio.h>
#include <string.h>

#define SIZE 80

struct std
{
    unsigned int id;
    // char *name;
    char name[SIZE];
    /*
    Ҫ�ڽṹ���д洢�ַ���ʱ������ѡ���ַ����飬�������ַ�ָ��
    ��Ϊ�ṹ��ı�������Ҫ�ַ����ڽṹ����ռ��һ�����ڴ�ռ䣬��ָ��ֻ�ܴ���ַ����ĵ�ַ
    */
    unsigned int age;
}per;

int main()
{
    per.id = 0001;
    strcpy(per.name, "Micheal Jackson"); // ���������ַ����������ṹ�����ڵ��ڴ�ռ���
    // per.name = "Micheal Jackson"; // �ڽṹ����ʹ���ַ�ָ��ʱ������������������ָ��ָ���������ַ������׵�ַ
    // ��Ҳ������õķ�������Ϊ�ַ�����������ھ�ֻ̬��������û���ڽṹ����ռ���ڴ�ռ�
    per.age = 20;

    printf("%s\n", per.name);

    return 0;
}