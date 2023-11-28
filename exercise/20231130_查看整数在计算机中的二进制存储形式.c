#include <stdio.h>

void show_bits(int x);

int main() {
    int a = 8, b = -8;

    show_bits(a); // 正数：原码、反码、补码三码合一
    show_bits(b); // 负数：原码除符号位外其余各位取反得反码，反码加一得补码

    return 0;
}

void show_bits(int x) {
    for (int i = 0; i < 32; i ++) // 已知int类型的变量占四个字节，32位
        printf("%d", (x & (1 << (31 - i))) ? 1 : 0);
    printf("\n");
}