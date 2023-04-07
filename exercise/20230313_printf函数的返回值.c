#include <stdio.h>

int main()
{
    int i = 43;
    printf("%d\n", printf("%d", printf("%d", i))); //4321(回车)
    
    /*printf函数的返回值是打印字符的个数
    1) printf("%d", i) --> 输出43，返回2
    2) printf("%d", printf("%d", i)) = printf("%d", 2) --> 输出432，返回1
    3) printf("%d\n", printf("%d", printf("%d", i))) = printf("%d\n", 1) --> 输出4321，返回4
    */

    printf("%d\n", 5); //5

    return 0;
}