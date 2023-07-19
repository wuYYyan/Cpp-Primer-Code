#include <stdlib.h>

struct A
{
    char a; //对齐数为1
    char b; //对齐数为1
    int c;  //对齐数为4
};

struct B
{
    char a; //对齐数为1
    int c;  //对齐数为4
    char b; //对齐数为1
};

int main()
{
    printf("size of struct A = %llu\n", sizeof(struct A)); //8
    printf("size of struct B = %llu\n", sizeof(struct B)); //12

    /*
    结构体大小的计算要遵循结构体内存对齐规则(暂不考虑结构体的嵌套问题)：
    1) 第一个成员在与结构体变量偏移量为0的地址处
    2) 其他成员变量每次都要从【自身对齐数的整数倍】的地址处开始存放
    3) 结构体的总大小为其中各成员的最大对齐数(每一个成员变量都有一个对齐数)的整数倍
    4) 成员变量的对齐数 = 该结构体成员变量自身的大小与编译器默认的一个对齐数的较小值
    */

    return 0;
}