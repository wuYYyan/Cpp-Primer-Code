#include <stdio.h>

#define PRINT_NUMS(...) printf(__VA_ARGS__)
// __VA_ARGS__ ȫ��Ϊ��variable argument lists����C�����е�һ��Ԥ��������
// �����ڱ�ʾ�ɱ�����б����Խ������������Ĳ���

#define PRINTF_STRING ({ printf("Hello World!\n"); printf("===========\n"); printf("Hello World!\n");})
// ��������������� {} ��Χ��һ����䣬����������Ҫһ�����ĵط�ʹ�ã�����һ�����������һ��

int main() {
    PRINT_NUMS("%d %d %d %d\n", 1, 2, 3, 4);

    PRINTF_STRING;

    return 0;
}