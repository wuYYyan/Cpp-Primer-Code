#include <stdlib.h>

struct A
{
    double a; //对齐数为8
    char b;   //对齐数为1
    int c;    //对齐数为4
};

struct B
{
    char d; //对齐数为1
    struct A e; //注意结构体成员变量的对齐数为自身大小与默认对齐数的较小值，对齐数为8
    double f; //对齐数为8
};

int main()
{
    printf("size of struct A = %d\n", sizeof(struct A)); //16
    printf("size of struct B = %d\n", sizeof(struct B)); //32

    /*
    结构体大小的计算要遵循结构体内存对齐规则(结构体的嵌套问题同)：
    1) 第一个成员在与结构体变量偏移量为0的地址处
    2) 其他成员变量每次都要对齐到自身对齐数的整数倍的地址处
    3) 结构体的总大小为最大对齐数(每一个成员变量都有一个对齐数)的整数倍
    4) 成员变量的对齐数 = 该结构体成员变量自身的大小与编译器默认的一个对齐数的较小值
    */

    return 0;
}