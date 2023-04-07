#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *p1 = "wuyan"; //
    char *p2 = (char *)malloc(strlen(p1) + 1);
    //函数strlen()在计算字符串长度时不会把末尾的结束符'\0'计算在内
    //但是函数strcpy()在拷贝字符串时会连通末尾的结束符'\0'一起拷贝
    //因此在开辟内存空间时就需要多开辟一个字节，保证字符串有结束符
    strcpy(p2, p1);
    printf("%s\n", p2);
    return 0;
}