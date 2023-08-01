#include <iostream>

using namespace std;

int main()
{
    /* C和C++中const的区别是什么？
    1) 编译方式不同，C++中所有出现const常量名字的地方都被常量的初始值替换了
        而C中const常变量就是当做一个变量来编译生成指令的
    */
   
    // const int x; //在C++中，const修饰的量称为常量，一定要初始化，否则在编译阶段就会报错
    // const修饰的变量不能够再作为左值，初始化完成之后，值不能再被修改

    const int a = 10;
    printf("a = %d\n", a);

    int arr[a] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //因为在编译阶段会把a替换为10，所以可以作为数组的大小
    printf("arr[0] = %d\n", arr[0]);

    // const int *p = &a; //a是常量，p是指向常量的指针(底层const)
    int *p = (int*)&a; //通过强制类型转换，将const int*转换成int*
    *p = 20;
    // 指针p本质上已经修改了a的值，但因为在编译阶段就作了常量替换，所以最终的输出值不一样
    printf("%p\n", &a);
    printf("%p\n", p);
    printf("a = %d\n", a); //10，因为编译器在编译阶段作了常量替换，所以这里其实和a的值无关
    printf("*p = %d\n", *p); //20，已经通过指针把a所标识的内存块中的变量进行了修改
    printf("*(&a) = %d\n", *(&a)); //10

    return 0;
}