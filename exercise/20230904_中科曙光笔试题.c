#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "wuyan1";
    char str2[] = "wuyan2";

    strcpy(str1, str2); // 将str2中的字符串拷贝到str1中
    printf("%s\n", str1);

    strcpy(str2, "wuyan3");
    printf("%s\n", str2);

    return 0;
}