#include <stdio.h>
#include <string.h>

#define SIZE 80

struct std
{
    unsigned int id;
    //char *name;
    char name[SIZE];
    /*
    要在结构体中存储字符串时，优先选用字符数组，而不是字符指针
    因为结构体的本意是想要字符串在结构体中占用一定的内存空间，而指针只能存放字符串的地址
    */
    unsigned int age;
}per;

int main()
{
    per.id = 0001;
    strcpy(per.name, "Micheal Jackson");
    //per.name = "Micheal Jackson"; //在结构体中使用字符指针时可以这样做，但也不是最好的方法，因为字符串常量存放在静态只读区
    per.age = 20;

    printf("%s\n", per.name);

    return 0;
}