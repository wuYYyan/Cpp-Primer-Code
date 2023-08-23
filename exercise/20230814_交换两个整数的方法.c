// 已知有两个变量a = 10、b = 20，要求将两个变量的值进行交换
// 最终打印结果为：a = 20、b = 10
#include <stdio.h>

int main()
{
    // 方法一：借助中间变量
    int a1 = 10, b1 = 20;
    int temp;
    temp = a1;
    a1 = b1;
    b1 = temp;
    printf("1) a1 = %d, b1 = %d\n", a1, b1);

    // 方法二：利用运算符优先级进行交换
    int a2 = 10, b2 = 20;
    b2 = (a2 + b2) - (a2 = b2); // 等式右边从左向右依次执行
    printf("2) a2 = %d, b2 = %d\n", a2, b2);

    // 方法三：算术运算
    int a3 = 10, b3 = 20;
    a3 = b3 - a3;
    b3 = b3 - a3;
    a3 = a3 + b3;
    printf("3) a3 = %d, b3 = %d\n", a3, b3);

    // 方法四：异或位运算，相同为0，相异为1
    int a4 = 10, b4 = 20;
    a4 = a4 ^ b4;
    b4 = a4 ^ b4;
    a4 = a4 ^ b4;
    printf("4) a4 = %d, b4 = %d\n", a4, b4);

    return 0;
}