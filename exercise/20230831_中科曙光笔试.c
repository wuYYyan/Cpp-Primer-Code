#include <stdio.h>

int main()
{
    // 选择题1
    unsigned int a = 0XFFFF;
    printf("%u\n", a); // 65535

    // 选择题2
    char *ps = "wuyan";
    printf("%c\n", ps[0]); // w
    printf("%c\n", ps[3]); // a
    printf("%s\n", ps); // wuyan
    ps[3] = 'y'; // error，下面的两行都无法执行，
    // 因为ps指向的是常量区，常量区的内容是不可修改的
    printf("%c\n", ps[3]); // a;
    printf("%s\n", ps); // wuyan

    // 选择题3
    char s[] = "wuyan";
    printf("%d\n", sizeof(s)); // 6，不会把数组名当成指针
    // s += 2; // error，数组名是常量，不可修改
    
    // 选择题4
    int a = 1; int b = 2; // 允许一行有多条语句
    int c 
     = a + b; // 允许一条语句分割多行
    // C++是按照分号来进行语句分割的，与Python不同

    // 选择题5
    // int 123a = 1; // error，变量名不能以数字开头
    int _1 = 2; // 变量中可以包含字母、数字、下划线，但只能以字母或下划线开头

    // 选择题6
    
}