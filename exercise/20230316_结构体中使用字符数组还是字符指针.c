#include <stdio.h>
#include <string.h>

#define SIZE 80

struct std
{
    unsigned int id;
    // char *name;
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
    strcpy(per.name, "Micheal Jackson"); // 将所给的字符串拷贝到结构体所在的内存空间中
    // per.name = "Micheal Jackson"; // 在结构体中使用字符指针时可以这样做，这是让指针指向了所给字符串的首地址
    // 但也不是最好的方法，因为字符串常量存放在静态只读区，并没有在结构体中占用内存空间
    per.age = 20;

    printf("%s\n", per.name);

    return 0;
}