#include <stdio.h>

void show_bits(int x);

int main() {
    int a = 8, b = -8;

    show_bits(a); // ������ԭ�롢���롢���������һ
    show_bits(b); // ������ԭ�������λ�������λȡ���÷��룬�����һ�ò���

    return 0;
}

void show_bits(int x) {
    for (int i = 0; i < 32; i ++) // ��֪int���͵ı���ռ�ĸ��ֽڣ�32λ
        printf("%d", (x & (1 << (31 - i))) ? 1 : 0);
    printf("\n");
}