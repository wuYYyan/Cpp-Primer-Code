#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "wuyan1";
    char str2[] = "wuyan2";

    strcpy(str1, str2); // ��str2�е��ַ���������str1��
    printf("%s\n", str1);

    strcpy(str2, "wuyan3");
    printf("%s\n", str2);

    return 0;
}