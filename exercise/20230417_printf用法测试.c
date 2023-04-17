#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str = "A string with % may not work.\n";

    printf("%s", str); //用%s输出字符串，输出：A string with % may not work.
    printf(str); //输出：A string with may not work.
    //这种用法也是符合规范的，但是会发生意想不到的错误，所以并不推荐

    char *str2 = "i want to print %d\n";
    printf("%s", str2);
    printf(str2); // 输出：i want to print 1337215536

    //额外测试
    puts("---------------");
    printf("%d\n", sizeof(str)); //输出8，计算的是指针本身所占内存的大小
    printf("%d\n", sizeof(*str)); //输出1，计算的是指针指向的内存的大小，
                                           //char型指针当然指的是单个字符，而不是整个字符串
    int len = strlen(str); //函数strlen要求传入的参数是const char *类型，所以这里的str是合法的，而不能传入*str
    printf("%d\n", len); //输出30，strlen计算的是字符串的长度，不包括'\0'
    //printf("%d\n", strlen(str)); //这样写会报错的，因为函数strlen的返回类型为size_t
                                   //而printf的格式化字符串中的%d只能接受int类型的参数

    return 0;
}