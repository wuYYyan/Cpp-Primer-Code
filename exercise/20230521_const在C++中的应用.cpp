#include <iostream>

using namespace std;

int main()
{
    /* C和C++中const的区别是什么？
    1) const的编译方式不同，C++中const修饰的变量会在编译阶段被替换成对应的值，而C中const就是当做一个变量来编译生成指令的
    */
   
    //const int x; //在C++中，const修饰的量称为常量，一定要初始化，否则会在编译阶段报错

    const int a = 10;
    printf("a = %d\n", a);

    int arr[a] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //常量可以作为数组大小，因为在编译阶段会把a替换为10
    printf("arr[0] = %d\n", arr[0]);

    // const int *p = &a; //a是常量，p是指向常量的指针(底层const)
    int *p = (int*)&a; //通过强制类型转换，将const int*转换成int*
    *p = 20;
    // 指针p本质上已经修改了a的值，但因为在编译阶段就作了常量替换，所以最终的输出值不一样
    printf("%p\n", &a);
    printf("%p\n", p);
    printf("a = %d\n", a); //10，因为编译器在编译阶段作了常量替换，所以这里其实和a的值无关
    printf("*p = %d\n", *p); //20

    return 0;
}