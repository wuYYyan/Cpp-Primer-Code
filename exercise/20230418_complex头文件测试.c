#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {
    double complex z = 1.0 + 1.0 * I;
    double complex result = cexp(z); //对复数z进行以e为底的指数运算
    // z = x + jy  result = e^(x + jy) = e^x * e^(jy) = e^x * (cos(y) + j * sin(y)) (x、y为实数，代入三角函数时的单位为弧度)
    printf("cexp(%.1f + %.1fi) = %.2f + %.2fi\n", creal(z), cimag(z), creal(result), cimag(result));
    return 0;
}