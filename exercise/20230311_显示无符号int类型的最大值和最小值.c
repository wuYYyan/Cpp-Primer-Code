#include <stdio.h>

int main()
{
    unsigned int i = 0;
    printf("i = %ud\n", i);

    unsigned int j = ~0; //在不知道系统位数时，通过对最小值的每一位取反得到最大值
    printf("j = %ud\n", j);

    //printf("%d", sizeof(int));

    return 0;
}