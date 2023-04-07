#include <stdio.h>

#define XNAME(n)    x##n //实现 x 与 n 的黏合，使编译器将两个语言符号看作是一个语言符号

int main()
{
    //int x1 = 10;
    int XNAME(1) = 10;
    printf("%d\n", x1);

    return 0;
}