#include <stdlib.h>
#include <stdio.h>

int main()
{
    if(printf("*")) //printf函数的返回值是打印字符的个数，因此条件判断为真
        puts("1) One");
    
    if("0") //字符串常量值的本质是地址，因此条件判断为真
        puts("2) Two");

    if('0') //字符‘0’的ASCII码值为48，因此条件判断为真
        puts("3) Three");
    
    if(0) //数值0转换为条件表达式为false，因此条件判断为假
        puts("4) Four");

    if("\0") //字符串常量值的本质是地址，因此条件判断为真
        puts("5) Five");

    if("") //字符串常量值的本质是地址，因此条件判断为真
        puts("6) Six");

    int *p = 0; //常量整数值0隐式转换为指针
    if(p) //当指针的值为0时，隐式转换为布尔类型的结果为false，因此条件判断为假
        puts("7) Seven");

    return 0;
}