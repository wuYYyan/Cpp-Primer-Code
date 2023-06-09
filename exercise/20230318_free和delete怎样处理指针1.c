//问题：在C和C++中，free()和delete是如何操作指向动态开辟内存的指针的？
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *p = (char *)malloc(100);
    strcpy(p, "wuyan");
    printf("p = %s\n", p);
    printf("sizeof(p) = %d\n", (int)sizeof(p)); //计算指针p本身所占内存空间的大小，而不是p所指向的内存空间的大小
    printf("strlen(p) = %d\n", (int)strlen(p)); //strlen()本质上是一个函数


    free(p); //free()本质上是一个函数
    printf("p = %s\n", p);
    if (p != NULL) //C语言中，用NULL表示空指针
    {
        strcpy(p, "Hello World");
        printf("p = %s\n", p);
    }
    //通过以上程序可以看出，函数free()只是把动态开辟的内存释放掉，即用户最好不要再使用，有可能存放的是垃圾值
    //而对指向该内存空间的指针不做销毁处理，所以还能再对其赋值
    //但是这种做法并不安全，指针有可能指向无法访问的空间，所以进行如下操作
    p = NULL;

    // new：对象构造、内存分配、返回指针
    // delete：对象析构、内存释放、注意并不销毁指针
        

    return 0;
}