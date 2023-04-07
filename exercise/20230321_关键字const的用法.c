#include <stdio.h>

int main()
{
    const int a = 5;
    //const修饰的变量必须在定义的同时赋初值，否则以后就没有机会了
    printf("a = %d\n", a);

    //但是使用const修饰的变量并不是真正意义上的常量，可以通过如下方式修改
    int *p = &a;
    *p = 4;
    printf("a = %d\n", a);
    
    //上面的代码在视频里就可以更改，为啥我这里不行

    //int arr[a] = {1, 2, 3, 4, 5}; //报错，可见a在编译器看来并不是真正的常量

    return 0;
}