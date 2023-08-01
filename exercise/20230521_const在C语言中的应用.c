#include <stdio.h>

int main()
{
    /* C和C++中const的区别是什么？
    1) const的编译方式不同，C++中所有出现const常量名字的地方都被常量的初始值替换了
        而C中const常变量就是当做一个变量来编译生成指令的
    */
   
    const int x; //在C语言中，const修饰的量称为常变量，不一定非要初始化(大多数情况下视为变量)
    // 如果像上面这样定义，x的值就无法再被使用了，因为const修饰的变量不能作为左值

    const int a = 10;
    printf("a = %d\n", a);

    // int arr[a] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //变量不能作为数组大小，所以编译阶段会报错
    // printf("arr[0] = %d\n", arr[0]);

    // const int *p = &a; //a是常量，p是指向常量的指针(底层const)
    int *p = (int*)&a; //通过强制类型转换，将const int*转换成int*
    *p = 20;
    // 输出的地址是一样的，输出的值也一样，即通过指针修改了常变量的值
    printf("%p\n", &a);
    printf("%p\n", p);
    printf("a = %d\n", a); //20
    printf("*p = %d\n", *p); //20
    printf("*(&a) = %d\n", *(&a)); //20

    return 0;
}