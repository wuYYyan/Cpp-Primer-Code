#include <stdio.h>

int main() {
    float a = 98765432198e10;
    float b;

    b = a + 0.01;
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    /*
    float�ı�ʾ����ֻ����λ��������λ֮��᲻׼ȷ
    ���������������ܴ�������м��㣬����ᶪʧ����
    */

    return 0;
}