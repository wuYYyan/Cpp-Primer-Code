#include <stdio.h>

int main() {

    char *s1 = "123456789";
    printf("size s1 = %lu\n", sizeof(s1)); // ����ָ����ռ�õ��ڴ�ռ�

    char s2[] = "123456789";
    printf("size s2 = %lu\n", sizeof(s2));
    // sizeof�����������������ַ�����Ǽ�������������ռ�õ��ڴ�ռ�

    char s3[100] = "123456789";
    printf("size s3 = %lu\n", sizeof(s3));

    int s4[100];
    printf("size s4 = %lu\n", sizeof(s4));

    char *s5 = "a\n";
    printf("size s5 = %lu\n", sizeof(s5));

    char s6[] = "a\n";
    printf("size s6 = %lu\n", sizeof(s6));

    return 0;
}