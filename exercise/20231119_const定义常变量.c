#include <stdio.h>

int main() {
    const int x = 3;
    printf("x = %d\n", x);

    int *p = &x;
    *p = 4;
    printf("x = %d\n", x); // ֤�����ǿ���ͨ��ָ�����޸�x��ֵ

    // int arr[x] = {1, 2, 3, 4}; // error��������ʹ�ñ������������С

    return 0;
}