#include <stdio.h>

int main() {
    float a = 98765432198e10;
    float b;

    b = a + 0.01;
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    /*
    float的表示精度只有七位，超过七位之后会不准确
    尽量避免两个相差很大的数进行计算，否则会丢失数据
    */

    return 0;
}